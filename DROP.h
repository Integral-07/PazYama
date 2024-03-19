#pragma once
#include "Actor.h"

class Drop :
    public Actor
{
public:
    Drop(class Game* game, int kind);

    void UpdateActor() override;
    void SetSpeed(float speed);
    void SetDirection(const VECTOR2& direction);

public:
    const VECTOR2& GetPositionOnBoard() const { return mPositionOnBoard; }
    int GetKind() const { return mKindOfDrop; }
    void SetKind(int kind) { mKindOfDrop = (DROP_KIND)kind; }

    bool EnableToDrop();  //落ちれる判定
    
    enum DROP_KIND {

        NONE = -1,

        GRAPE,     //紫
        PEACH,     //ピンク
        FUJI,      //青
        CRYSTAL,   //白
        TEMP1,     //
        TEMP2,     //
        NUM_DROPS, //ドロップの個数

        SENTINEL   //番兵
    };
private:

    DROP_KIND mKindOfDrop;
    VECTOR2 mPositionOnBoard;    //自分がボードのどの行・列にいるか

    bool mSelected;

private:
    class RectComponent* mRect;

    class MoveComponent* mMc;
};

