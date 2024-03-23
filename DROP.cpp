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
	: Actor(game), mSelectedFlag(false), mAligned(false),mOldAligned(false), mPositionOnBoard(0,0), mKindOfDrop((DROP_KIND)kind)
{
	SetScaleW(70);
	SetScaleH(70);

	mSc = new SpriteComponent(this, 190);

	switch ((DROP_KIND)kind) {
	case GRAPE:
		mSc->SetImage(LoadGraph("Assets\\drop00.jpeg"));
		break;
	case PEACH:
		mSc->SetImage(LoadGraph("Assets\\drop01.jpeg"));
		break;
	case FUJI:
		mSc->SetImage(LoadGraph("Assets\\drop02.jpeg"));
		break;
	case CRYSTAL:
		mSc->SetImage(LoadGraph("Assets\\drop03.jpeg"));
		break;
	case TEMP1:
		mSc->SetImage(LoadGraph("Assets\\drop04.jpeg"));
		break;
	case TEMP2:
		mSc->SetImage(LoadGraph("Assets\\drop05.jpeg"));
		break;
	case SENTINEL:
		mSc->SetImage(LoadGraph("Assets\\sentinel.jpeg"));
		break;
	}

}

void Drop::UpdateActor()
{
	if (mGame->GetGameState() == Game::EFall) {

		if (mKindOfDrop != SENTINEL 
			&& mGame->GetBelowDrop(mPositionOnBoard)->GetKind() == NONE
			&& mKindOfDrop != NONE) {

		
			ExchangeDrops(mGame, this, mGame->GetBelowDrop(mPositionOnBoard));
			mGame->ExchangeDrops(mPositionOnBoard, VECTOR2(mPositionOnBoard.x + 1, mPositionOnBoard.y));
			
		}
		
	}

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
			//mGame->SetKind(mPositionOnBoard.x, mPositionOnBoard.y, NONE);
			//mAligned = false;
			mGame->GetDrop(mPositionOnBoard)->SetKind(NONE);
			mKindOfDrop = NONE;
		
		}
		
		if (mKindOfDrop == NONE) {

			//SetState(EDead);
			mSc->SetImage(LoadGraph("Assets\\panel.jpeg"));
			mSc->Draw();
		}

		IsAligned();

	}


	
}

void Drop::ActorInput()
{
	
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

	if (mGame->GetDrop(VECTOR2(row + dir_row * num, line + dir_line * num))->GetKind() == NONE) {

		return 0;
	}

	while (mGame->GetDrop(VECTOR2(row + dir_row * num, line + dir_line * num))->GetKind() == mKindOfDrop) {
		//他種ドロップまたは番兵であれば終了

		num++;
	}

	return num - 1;
}

int Drop::CheckNone(int row, int line, int dir_row, int dir_line)
{
	int num = 1;

	while (mGame->GetDrop(VECTOR2(row + dir_row * num, line + dir_line * num))->GetKind() == NONE) {
		//NONEでなければ終了

		num++;
	}

	return num - 1;
}

bool Drop::IsAligned()
{

	if (mKindOfDrop == Drop::SENTINEL) {

		return false;
	}
	else if (mKindOfDrop == Drop::NONE) {

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
		mGame->GetDrop(mPositionOnBoard)->SetAlignedFlag(true);
	}

	return false;
}


