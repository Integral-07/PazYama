#include "Actor.h"
#include "SpriteComponent.h"
class BackGround : public Actor{

public:
	BackGround(class Game* game);
	void SetImage(int handle) {

		mSc->SetImage(handle);
	}

private:

	SpriteComponent* mSc;
};