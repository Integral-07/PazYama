#pragma once
#include "MoveComponent.h"
class InputComponent :
    public MoveComponent
{
public:
    InputComponent(class Actor* owner);

    void ProcessInput() override;
    void SetMoveSpeed(float speed) { mMoveSpeed = speed; }

private:
    float mMoveSpeed;
};

