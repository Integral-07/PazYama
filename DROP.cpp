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

	mRect = new RectComponent(this, 110);
	mRect->SetHalfWidth(mScaleW/2);
	mRect->SetHalfHeight(mScaleH/2);
}

void Drop::UpdateActor()
{

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

	if (mSelectedFlag) {

		SetScaleW(70 * 1.2);
		SetScaleH(70 * 1.2);

		
	}
	else {

		SetScaleW(70);
		SetScaleH(70);
	}

	IsAligned();

	if (mState == EActive) {

		if (mAligned) {

			SetState(EDead);
			//mGame->DeleteDrop(this);
		}
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

int Drop::CheckDir(int row, int line, int dir_row, int dir_line)
{
	int num = 1;

	auto& vec = mGame->GetDrops();

	while (vec[(PuzSize + 2) * (row + dir_row * num) + (line + dir_line * num)]->GetKind() == mKindOfDrop) {
		//他種ドロップまたは番兵であれば終了

		num++;
	}

	return num;
}

bool Drop::IsAligned()
{

	if (mKindOfDrop == Drop::SENTINEL) {

		return false;
	}

	for (int dir_row = -1; dir_row < 2; dir_row++) {
		for (int dir_line = -1; dir_line < 2; dir_line++) {

			if (dir_row != 0 && dir_line != 0 
				|| dir_row == 0 && dir_line == 0) {

				continue;
			}

			if (CheckDir(mPositionOnBoard.x, mPositionOnBoard.y, dir_row, dir_line) >= 3) {

				mAligned = true;
				return true;
			}
		}
	}

	return false;
}


