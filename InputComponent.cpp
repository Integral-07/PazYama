#include "InputComponent.h"
#include "Key.h"

InputComponent::InputComponent(Actor* owner)
	: MoveComponent(owner), mMoveSpeed(0.0f)
{
}

void InputComponent::ProcessInput()
{
	VECTOR2 dir(0, 0);

	if (KeyDown(KEY_INPUT_UP)) {
		
		dir.y = -1;
	}
	else if (KeyDown(KEY_INPUT_DOWN)) {

		dir.y = 1;
	}
	

	if (KeyDown(KEY_INPUT_LEFT)) {

		dir.x = 1;
	}
	else if (KeyDown(KEY_INPUT_RIGHT)) {

		dir.x = -1;
	}

	SetSpeed(0);
	if (dir.x != 0 || dir.y != 0) {

		SetSpeed(mMoveSpeed);
		SetDirection(normalize(dir));
	}
}
