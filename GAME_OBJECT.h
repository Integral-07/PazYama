#pragma once
#include "GAME.h"
class GAME_OBJECT
{
public:
	GAME_OBJECT(class GAME* game);
	virtual ~GAME_OBJECT();

	class GAME* game() { return Game; }

private:
	class GAME* Game = 0;
};

