#include "Selector.h"
#include "InputComponent.h"
#include "SpriteComponent.h"
#include "RectComponent.h"
#include "DxLib.h"
#include "fps.h"
#include "Key.h"
#include "Game.h"

Selector::Selector(class Game* game)
	:Actor(game)
{
	SetScaleW(70);
	SetScaleH(70);
	SetPosition(VECTOR2(mScaleW * mRow * 2, mScaleH * mLine * 2));

	auto sc = new SpriteComponent(this, 200);
	sc->SetImage(LoadGraph("Assets\\frame.jpeg"));
	
	/*
	auto a = new MoveComponent(this);
	a->SetSpeed(100.0f);
	a->SetDirection(VECTOR2(1, 0));

	mIc = new InputComponent(this);
	mIc->SetMoveSpeed(300.0f);
	*/

	//mRc = new RectComponent(this, 120);
	//mRc->SetHalfHeight(mScaleH/2);
	//mRc->SetHalfWidth(mScaleW/2);
}


void Selector::ActorInput()
{
	VECTOR2 dir = mPosition;

	if (KeyClick(KEY_INPUT_UP)) {

		if (mRow - 1 >= 1) {

			dir.y += -mScaleH;
			mRow--;

			if (mSelected != nullptr
				&& mGame->GetAboveDrop(mSelected->GetPositionOnBoard())->GetKind() != Drop::SENTINEL) {

				ExchangeDrops(mGame, mSelected, mGame->GetAboveDrop(mSelected->GetPositionOnBoard()));
			}
		}
	}
	else if (KeyClick(KEY_INPUT_DOWN)) {

		if (mRow + 1 <= PuzSize) {
			
			dir.y += mScaleH;
			mRow++;

			if (mSelected != nullptr
				&& mGame->GetBelowDrop(mSelected->GetPositionOnBoard())->GetKind() != Drop::SENTINEL) {

				ExchangeDrops(mGame, mSelected, mGame->GetBelowDrop(mSelected->GetPositionOnBoard()));
			}
		}
	}
	else if (KeyClick(KEY_INPUT_LEFT)) {

		if (mLine - 1 >= 1) {

			dir.x += -mScaleW;
			mLine--;
			
			if (mSelected != nullptr 
				&& mGame->GetLeftDrop(mSelected->GetPositionOnBoard())->GetKind() != Drop::SENTINEL) {

				ExchangeDrops(mGame, mSelected, mGame->GetLeftDrop(mSelected->GetPositionOnBoard()));
			}
		}
	}
	else if (KeyClick(KEY_INPUT_RIGHT)) {

		if (mLine + 1 <= PuzSize) {

			dir.x += mScaleW;
			mLine++;

			if (mSelected != nullptr
				&& mGame->GetRightDrop(mSelected->GetPositionOnBoard())->GetKind() != Drop::SENTINEL) {

				ExchangeDrops(mGame, mSelected, mGame->GetRightDrop(mSelected->GetPositionOnBoard()));
			}
		}
	}
	else if (KeyClick(KEY_INPUT_RETURN)){

		if (mGame->GetDrop(mRow, mLine)->GetSelected()) {


			mSelected = nullptr;
			
			mGame->GetDrop(mRow, mLine)->SelectedSignal();

			mGame->SetGameState(Game::EComb);
		}
		else {

			mSelected = mGame->GetDrop(mRow, mLine);
			mGame->GetDrop(mRow, mLine)->SelectedSignal();
		}

	}

	mPosition = dir;
}

void Selector::UpdateActor()
{
	
}
