#include "DROP.h"
#include "CONTAINER.h"

DROP::DROP(GAME* game)
	:GAME_OBJECT(game)
{
}

void DROP::create()
{ 
	Drop = game()->container()->drop();
}

void DROP::init()
{
}

void DROP::update()
{
}

void DROP::draw()
{
}
