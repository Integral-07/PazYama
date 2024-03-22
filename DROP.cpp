#include "Drop.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "RectComponent.h"
#include "InputComponent.h"
#include "Actor.h"
#include "Game.h"
#include "DxLib.h"
#include <string>
#include <random>
#include "Key.h"


Drop::Drop(Game* game, int kind) 
	: Actor(game), mSelectedFlag(false), mFallFlag(false),mPositionOnBoard(0,0), mKindOfDrop((DROP_KIND)kind)
{
	SetScaleW(70);
	SetScaleH(70);

	auto sc = new SpriteComponent(this, 150);

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
	case SENTINEL:
		sc->SetImage(LoadGraph("Assets\\sentinel.jpeg"));
		break;
	}
	
	mMc = new MoveComponent(this);
	mMc->SetSpeed(100);
	mMc->SetDirection(VECTOR2(0, 1));

	mRect = new RectComponent(this, 110);
	mRect->SetHalfWidth(mScaleW/2);
	mRect->SetHalfHeight(mScaleH/2);
}

void Drop::UpdateActor()
{
	/*
	if (mKindOfDrop != SENTINEL && mGame->GetKind(mPositionOnBoard.x + 1, mPositionOnBoard.y) == NONE) {

		mGame->SetKind(mPositionOnBoard.x, mPositionOnBoard.y, NONE); //自分の今いる行列をNONEにする
		mMc->SetSpeed(300.0f);
		if (Intersect(mRect, mBelowDrop->GetRect())) {

			mMc->SetSpeed(0.0f);
			mGame->SetKind(mBelowDrop->GetPositionOnBoard().x - 1, mPositionOnBoard.y, mKindOfDrop);
			
		}
	}
	if (mFallFlag) {

		mMc->SetSpeed(100);
		mMc->SetDirection(VECTOR2(0, 1));

		//これより前にmDropsの更新はしておくこと
		auto& vec = mGame->GetDrops();
		int min_row = 1000;
		Drop* min_drop = new Drop(mGame, SENTINEL);
		for (auto iter = vec.begin(); iter != vec.end(); iter++) {

			if ((*iter)->GetPosition().y == mPosition.y
				&& (*iter)->GetPosition().x < mPosition.x) {
				//列が同じで自分以下の行

				min_row < (*iter)->GetPosition().x ? NULL : min_drop = *iter;
			}
		}


		if (Intersect(mRect, min_drop->GetRect())) {

			mMc->SetSpeed(0);
			mFallFlag = false;
		}
	}
	*/

	if (mSelectedFlag) {

		SetScaleW(70 * 1.1);
		SetScaleH(70 * 1.1);

		
	}
	else {

		SetScaleW(70);
		SetScaleH(70);
	}


	if (mGame->GetGameState() == Game::EComb) {

		if (mAligned) {

			SetState(EDead);
			mGame->SetKind(mPositionOnBoard.x, mPositionOnBoard.y, NONE);
		}

		if (!IsAligned()) {

			mGame->SetGameState(Game::EPuz);
		}

	}

	IsAligned();

	
}

void Drop::ActorInput()
{
	
}

void Drop::SetSpeed(float speed)
{
	mMc->SetSpeed(speed);
}

void Drop::SetDirection(const VECTOR2& direction)
{
	mMc->SetDirection(direction);
}

void ExchangeDrops(class Game* game, Drop* a, Drop* b)
{
	VECTOR2 temp_pos = a->GetPosition();
	VECTOR2 temp_posOnb = a->GetPositionOnBoard();


	a->SetPosition(b->GetPosition());
	a->SetPositionOnBoard(b->GetPositionOnBoard());

	b->SetPosition(temp_pos);
	b->SetPositionOnBoard(temp_posOnb);
	


	game->ExchangeDrops(a->GetPositionOnBoard(), b->GetPositionOnBoard());
}

int Drop::CheckDir(int row, int line, int dir_row, int dir_line)
{
	int num = 1;

	while (mGame->GetDrop(row + dir_row * num, line + dir_line * num)->GetKind() == mKindOfDrop) {
		//他種ドロップまたは番兵であれば終了

		num++;
	}

	return num - 1;
}

bool Drop::IsAligned()
{

	if (mKindOfDrop == Drop::SENTINEL) {

		return false;
	}
	int rensa_row = 0;
	int rensa_line = 0;
	for (int dir_row = -1; dir_row < 2; dir_row++) {
		for (int dir_line = -1; dir_line < 2; dir_line++) {

			if (dir_row != 0 && dir_line != 0 
				|| dir_row == 0 && dir_line == 0) {

				continue;
			}

			if (dir_row == 0) {

				rensa_row += CheckDir(mPositionOnBoard.x, mPositionOnBoard.y, dir_row, dir_line);
			}
			if (dir_line == 0) {

				rensa_line += CheckDir(mPositionOnBoard.x, mPositionOnBoard.y, dir_row, dir_line);
			}

			
		}
	}


	if (rensa_row+1 >= 3 || rensa_line+1 >= 3) {

		mAligned = true;
	}

	return false;
}


