#include "BackGround.h"
#include "SpriteComponent.h"
#include "DxLib.h"

BackGround::BackGround(class Game* game):Actor(game)
{
	 mSc = new SpriteComponent(this, 10);
}
