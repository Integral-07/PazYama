#pragma once
#include "GAME_OBJECT.h"
class DROP :
    public GAME_OBJECT
{
public:
    struct DATA {

        int img;
        VECTOR2 pos;
        float scale;
    };
private:
    DATA Drop;

public:
    DROP(class GAME* game);
    
    void create();
    void init();
    void update();
    void draw();
};

