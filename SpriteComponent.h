#pragma once
#include "Component.h"
class SpriteComponent :
    public Component
{
public:
    SpriteComponent(class Actor*, int drawOrder = 100);
    ~SpriteComponent() override;

    virtual void Draw();
    virtual void SetImage(int img);

    int GetDrawOrder() const { return mDrawOrder; }

private:


    int mImg;
    int mDrawOrder;
};

