#include "GAME_OVER.h"

GAME_OVER::GAME_OVER(class GAME* game) :SCENE(game)
{
}

GAME_OVER::~GAME_OVER()
{
}

void GAME_OVER::draw()
{
	DrawBox(100 - 10, 100 - 10, 500 + 10, 500 + 10, GetColor(0, 0, 0), true);
	DrawBox(100, 100, 500, 500, GetColor(0, 255, 0), true);

	//SetFontSize(200);
	//DrawString(0, 0, "GAME_OVER", GetColor(255, 255, 255));
}

void GAME_OVER::nextScene()
{
	game()->changeScene(GAME::RESULT_ID);
}