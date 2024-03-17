#include "CONTAINER.h"

void CONTAINER::load()
{
	setData();
}

void CONTAINER::setData()
{
	Data.title.textColor = GetColor(0, 255, 0);
	Data.title.fontSize = 200;
	Data.title.pos.x = 160;
	Data.title.pos.y = 200;
	strcpy_s(Data.title.text, "REVERSI");


	Data.drop.pos.x = 0;
	Data.drop.pos.y = 0;
	Data.drop.scale = 1.0f;
	
}
