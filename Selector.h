#pragma once
#include "Actor.h"
class Selector :
    public Actor
{
public:
    Selector(class Game* gmae);

    void UpdateActor() override;
    void ActorInput() override;
    
};

