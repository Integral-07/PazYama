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
	SetPosition(VECTOR2(PuzPosition.x + mScaleW * mRow * 2, PuzPosition.y + mScaleH * mLine * 2));

	auto sc = new SpriteComponent(this, 200);
	sc->SetImage(LoadGraph("Assets\\frame.jpeg"));
	
}


void Selector::ActorInput()
{
	VECTOR2 dir = mPosition;

	if (KeyDown(KEY_INPUT_UP)) {

		if (mRow - 1 >= 1) {

			dir.y += -mScaleH;
			mRow--;

			if (mSelected != nullptr
				&& mGame->GetAboveDrop(mSelected->GetPositionOnBoard())->GetKind() != Drop::SENTINEL) {

				ExchangeDrops(mGame, mSelected, mGame->GetAboveDrop(mSelected->GetPositionOnBoard()));
			}
		}
	}
	else if (KeyDown(KEY_INPUT_DOWN)) {

		if (mRow + 1 <= PuzSize) {
			
			dir.y += mScaleH;
			mRow++;

			if (mSelected != nullptr
				&& mGame->GetBelowDrop(mSelected->GetPositionOnBoard())->GetKind() != Drop::SENTINEL) {

				ExchangeDrops(mGame, mSelected, mGame->GetBelowDrop(mSelected->GetPositionOnBoard()));
			}
		}
	}
	else if (KeyDown(KEY_INPUT_LEFT)) {

		if (mLine - 1 >= 1) {

			dir.x += -mScaleW;
			mLine--;
			
			if (mSelected != nullptr 
				&& mGame->GetLeftDrop(mSelected->GetPositionOnBoard())->GetKind() != Drop::SENTINEL) {

				ExchangeDrops(mGame, mSelected, mGame->GetLeftDrop(mSelected->GetPositionOnBoard()));
			}
		}
	}
	else if (KeyDown(KEY_INPUT_RIGHT)) {

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

		if (mGame->GetDrop(VECTOR2(mRow, mLine))->GetSelected()) {


			mSelected = nullptr;
			
			mGame->GetDrop(VECTOR2(mRow, mLine))->SelectedSignal();

			mGame->SetGameState(Game::EComb);
		}
		else {

			mSelected = mGame->GetDrop(VECTOR2(mRow, mLine));
			mSelected->SelectedSignal();
		}

	}

	mPosition = dir;
}

void Selector::UpdateActor()
{
	
}
