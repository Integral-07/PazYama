#pragma once
#include "Actor.h"
#include "InputComponent.h"
#include "RectComponent.h"
#include "Drop.h"

class Selector :
    public Actor
{
public:
    Selector(class Game* gmae);
    void ActorInput() override;
    void UpdateActor() override;

private:
    
    Drop* mSelected = nullptr;

    int mRow = 1;
    int mLine = 1;

    int mSoundSelect;
    
};

