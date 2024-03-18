#pragma once
#include "Actor.h"

class Drop :
    public Actor
{
public:
    Drop(class Game* game);

    void UpdateActor() override;
    void SetSpeed(float speed);
    void SetDirection(const VECTOR2& direction);

private:
    class RectComponent* mRect;

    class MoveComponent* mMc;

    bool mSelected;
};

