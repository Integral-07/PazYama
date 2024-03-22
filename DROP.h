#pragma once
#include "Actor.h"
#include "RectComponent.h"

class Drop :
    public Actor
{
public:
    Drop(class Game* game, int kind);

    void UpdateActor() override;
    void ActorInput() override;
    void SetSpeed(float speed);
    void SetDirection(const VECTOR2& direction);
    void SetPositionOnBoard(const VECTOR2& pos) { mPositionOnBoard = pos; }
    
    //Drop* GetAboveDrop() const { return mAboveDrop; }
    //void SetAboveDrop(class Drop* drop) { mAboveDrop = drop; }

    //Drop* GetBelowDrop() const { return mBelowDrop; }
    //void SetBelowDrop(class Drop* drop) { mBelowDrop = drop; }

public:
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

    const VECTOR2& GetPositionOnBoard() const { return mPositionOnBoard; }
    DROP_KIND GetKind() const { return mKindOfDrop; }
    void SetKind(int kind) { mKindOfDrop = (DROP_KIND)kind; }

    bool GetSelected() const { return mSelectedFlag; }
    RectComponent* GetRect() const { return mRect; }
    //void ReConnect(){
    //
    //    mAboveDrop->SetBelowDrop(mBelowDrop);
    //    mBelowDrop->SetAboveDrop(mAboveDrop);
    //
    //    return;
    //}

    void SelectedSignal() { 

        if (mSelectedFlag) {

            mSelectedFlag = false;
        }
        else {

            mSelectedFlag = true;
        }
    }


private:

    DROP_KIND mKindOfDrop;
    VECTOR2 mPositionOnBoard;    //自分がボードのどの行・列にいるか

    bool mSelectedFlag;
    bool mFallFlag;
    bool mAligned;

    int CheckDir(int row, int line, int dir_row, int dirline);
    bool IsAligned();

private:
    class RectComponent* mRect;

    class MoveComponent* mMc;

    //class Drop* mAboveDrop = nullptr;
    //class Drop* mBelowDrop = nullptr;
};


void ExchangeDrops(class Game* game, Drop* a, Drop* b);