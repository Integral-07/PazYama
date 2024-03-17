#include "GAME_CLEAR.h"

GAME_CLEAR::GAME_CLEAR(class GAME* game) :SCENE(game)
{
}

GAME_CLEAR::~GAME_CLEAR()
{
}

void GAME_CLEAR::draw()
{
	DrawBox(100 - 10, 100 - 10, 500 + 10, 500 + 10, GetColor(0, 0, 0), true);
	DrawBox(100, 100, 500, 500, GetColor(0, 255, 0), true);

	//SetFontSize(200);
	//DrawString(0, 0, "GAME_CLEAR", GetColor(255, 255, 255));
}

void GAME_CLEAR::nextScene()
{
	game()->changeScene(GAME::RESULT_ID);
}