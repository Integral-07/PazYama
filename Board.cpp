#include "Board.h"
#include "SpriteComponent.h"
#include "DxLib.h"
#include <random>

Board::Board(Game* game) : Actor(game), mPosition(0,0)
{
	SetScaleW(168 * 2);
	SetScaleH(282 * 2);

	SetPosition(VECTOR2(100, 100));
	auto sc = new SpriteComponent(this, 110);
	sc->SetImage(LoadGraph("Assets\\Board.jpeg"));

	
}

void Board::UpdateActor()
{
}

void Board::AddDrop(Drop* drop)
{
	int no = PuzSize * (drop->GetPositionOnBoard().x) + (drop->GetPositionOnBoard().y);
	if (no >= 0 && no <= PuzSize * PuzSize - 1) {

		return;
	}

	mDropBoard[no] = drop;
}

void Board::RemoveDrop(Drop* drop)
{
	int no = PuzSize * (drop->GetPositionOnBoard().x) + (drop->GetPositionOnBoard().y);
	if (no >= 0 && no <= PuzSize * PuzSize - 1) {

		return;
	}

	delete mDropBoard[no];
}


bool Board::IsAlign(bool isDelete)
{

	for (auto iter=mDropBoard.begin(); iter != mDropBoard.end() ; iter++) {

		if ((*iter)->GetKind() == Drop::SENTINEL) {

			continue;
		}

		for (int dir_row = -1; dir_row < 2; dir_row++) {
			for (int dir_line = -1; dir_line < 2; dir_line++) {

				if (CheckDir((int)(*iter)->GetPositionOnBoard().x, (int)(*iter)->GetPositionOnBoard().y, dir_row, dir_line) >= 3) {

					if (isDelete) {

						SetState(EDead);
					}

					return true;
				}
			}
		}

	}
	return false;
}

void Board::GenerateNewDrop(int line, int kind)
{
	auto a = new Drop(mGame, kind);
	a->SetPosition(VECTOR2(0, line));
	a->SetSpeed(100);
}

void Board::GenerateNoneAlignedBoard()
{
	GenerateDropBoard(); //分散性保証なし生成

	while (true) {

		if (!IsAlign(true)) {

			break;
		}

		FillBlank();
	}
}

int Board::CheckDir(int row, int line, int dir_row, int dir_line)
{
	int num = 1;
	while (mDropBoard[PuzSize * (row + dir_row * num) + (line + dir_line * num)]->GetKind() == mDropBoard[PuzSize * row + line]->GetKind()) {
		//他種ドロップまたは番兵であれば終了

		num++;
	}

	return num;
}

void Board::GenerateDropBoard()
{
	srand(time(NULL));

	for (int i = 1; i < PuzSize + 1;i++) {
		for (int j = 1; j < PuzSize + 1;j++) {

			int k = rand() % Drop::NUM_DROPS;

			auto a = new Drop(mGame, k);
			a->SetPosition(VECTOR2(i, j));
			mDropBoard[PuzSize * i + j] = a;
		}
	}
}

void Board::FillBlank()
{
	int times = 0;
	for (auto iter = mBlank.begin(); iter != mBlank.end(); iter++, times++) {

		if (*iter == 1) {

			srand(time(NULL));
			GenerateNewDrop(times + 1, rand()%Drop::NUM_DROPS);
		}
	}
}
