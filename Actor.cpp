#include "Actor.h"
#include "Component.h"
#include "Game.h"

Actor::Actor(Game* game)
	: mGame(game), mState(EActive), mScaleW(1.0f), mScaleH(1.0f)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
}

void Actor::ProcessInput()
{
	if (mState == EActive) {

		for (auto component : mComponents) {

			component->ProcessInput();
		}

		ActorInput();
	}
}

void Actor::Update()
{
	if (mState == EActive) {

		for (auto component : mComponents) {

			component->Update();
		}

		UpdateActor();
	}
}

void Actor::AddComponent(Component* component)
{
	//ƒ\[ƒgÏ‚Ý”z—ñ‚Ì‘}“üêŠ‚ð’T‚·
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); iter++) {

		if (myOrder < (*iter)->GetUpdateOrder()) {

			break;
		}
	}

	mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end() - 1, component);
	if (iter != mComponents.end()) {

		mComponents.erase(iter);
	}
}


