#include "Selector.h"
#include "InputComponent.h"
#include "SpriteComponent.h"
#include "DxLib.h"

Selector::Selector(class Game* game)
	:Actor(game)
{
	auto sc = new SpriteComponent(this, 200);
	sc->SetImage(LoadGraph("Assets\\frame.jpeg"));
	

	auto ic = new InputComponent(this);
	ic->SetMoveSpeed(200);
}

void Selector::UpdateActor()
{
}

void Selector::ActorInput()
{
}
