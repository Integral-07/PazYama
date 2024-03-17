#pragma once
#include "SCENE.h"
class PLAY :
    public SCENE
{
public:
    PLAY(class GAME* game);
    ~PLAY() override;

    void draw() override;
    void nextScene() override;
};

