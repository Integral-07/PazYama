#pragma once
#include "Component.h"
#include "VECTOR2.h"

class RectComponent :
    public Component
{
public:
    RectComponent(class Actor* owner, int order);
    const VECTOR2& GetCenter() const;

    void SetHalfWidth(float width) { mHalfWidth = width; }
    void SetHalfHeight(float height) { mHalfHeight = height; }

    float GetHalfWidth() const { return mHalfWidth; }
    float GetHalfHeight() const { return mHalfHeight; }
    
private:

    float mHalfWidth;
    float mHalfHeight;
};

bool Intersect(const RectComponent* a, const RectComponent* b);

