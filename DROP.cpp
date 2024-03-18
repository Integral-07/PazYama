#include "Drop.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "RectComponent.h"
#include "DxLib.h"

Drop::Drop(Game* game) 
	: Actor(game), mSelected(false)
{
	SetScale(70);

	auto sc = new SpriteComponent(this);
	sc->SetImage(LoadGraph("Assets\\Drop01.jpeg"));
	
	mMc = new MoveComponent(this);
	mMc->SetSpeed(100);

	mRect = new RectComponent(this, 110);
	mRect->SetHalfWidth(mScale/2);
	mRect->SetHalfHeight(mScale/2);
}

void Drop::UpdateActor()
{
	/*
	VECTOR2 pos = GetPosition();
	if (Align()) {

		SetState(EDead);
		mGame->AddScore(100);
	}
	if (EnableToDrop()) {


	}
	*/

	if (mSelected) {

		DrawBox(mPosition.x, mPosition.y,
			mPosition.x + mScale, mPosition.y + mScale, 
			GetColor(0, 255, 0), true);
	}
}

void Drop::SetSpeed(float speed)
{
	mMc->SetSpeed(speed);
}

void Drop::SetDirection(const VECTOR2& direction)
{
	mMc->SetDirection(direction);
}

