#include "TITLE.h"

TITLE::TITLE(class GAME* game) :SCENE(game)
{
}

TITLE::~TITLE()
{
}

void TITLE::create()
{
}

void TITLE::draw()
{
	DrawBox(100 - 10, 100 - 10, 500 + 10, 500 + 10, GetColor(0, 0, 0), true);
	DrawBox(100, 100, 500, 500, GetColor(0, 255, 0), true);

	//SetFontSize(200);
	//DrawString(0, 0, "TITLE", GetColor(255, 255, 255));
}

void TITLE::nextScene()
{
	game()->changeScene(GAME::RESULT_ID);
}