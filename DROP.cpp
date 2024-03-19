#include "Drop.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "RectComponent.h"
#include "Game.h"
#include "DxLib.h"
#include <string>


Drop::Drop(Game* game, int kind) 
	: Actor(game), mSelected(false), mPositionOnBoard(0,0), mKindOfDrop((DROP_KIND)kind)
{
	SetScaleW(70);
	SetScaleH(70);

	auto sc = new SpriteComponent(this, 150);
	//sc->SetImage(LoadGraph("Assets\\drop05.jpeg"));

	
	switch ((DROP_KIND)kind) {
	case GRAPE:
		sc->SetImage(LoadGraph("Assets\\drop00.jpeg"));
		break;
	case PEACH:
		sc->SetImage(LoadGraph("Assets\\drop01.jpeg"));
		break;
	case FUJI:
		sc->SetImage(LoadGraph("Assets\\drop02.jpeg"));
		break;
	case CRYSTAL:
		sc->SetImage(LoadGraph("Assets\\drop03.jpeg"));
		break;
	case TEMP1:
		sc->SetImage(LoadGraph("Assets\\drop04.jpeg"));
		break;
	case TEMP2:
		sc->SetImage(LoadGraph("Assets\\drop05.jpeg"));
		break;
	}
	
	
	
	
	mMc = new MoveComponent(this);
	mMc->SetSpeed(100);

	mRect = new RectComponent(this, 110);
	mRect->SetHalfWidth(mScaleW/2);
	mRect->SetHalfHeight(mScaleH/2);
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
			mPosition.x + mScaleW, mPosition.y + mScaleH, 
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


bool Drop::EnableToDrop()
{
	if (((int)mPosition.x + 1, (int)mPosition.y) == NONE) {

		return true;
	}

	return false;
}


