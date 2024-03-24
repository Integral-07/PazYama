#pragma once
#include "Actor.h"
#include "SpriteComponent.h"

class Drop :
    public Actor
{
public:
    Drop(class Game* game, int kind);

    void UpdateActor() override;
    void ActorInput() override;

    void SetPositionOnBoard(const VECTOR2& pos) { mPositionOnBoard = pos; }


public:
    enum DROP_KIND {
        NONE = -1,

        GRAPE,     //紫
        PEACH,     //ピンク
        FUJI,      //青
        CRYSTAL,   //白
        PREFECTURE,//緑
        HOTO,
        NUM_DROPS, //ドロップの個数

        SENTINEL   //番兵
    };

    const VECTOR2& GetPositionOnBoard() const { return mPositionOnBoard; }
    DROP_KIND GetKind() const { return mKindOfDrop; }
    void SetKind(int kind) { mKindOfDrop = (DROP_KIND)kind; }

    bool GetSelected() const { return mSelectedFlag; }

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

    bool IsAligned();
    bool GetAlignedFlag() const { return mAligned; }
    void SetAlignedFlag(bool flag) { mAligned = flag; }

    void ReplaceNewDrop();

private:

    DROP_KIND mKindOfDrop;
    VECTOR2 mPositionOnBoard;    //自分がボードのどの行・列にいるか

    bool mSelectedFlag;
    bool mFallFlag;
    bool mAligned;
    bool mOldAligned;

    int CheckDir(int row, int line, int dir_row, int dirline);
    int CheckNone(int row, int line, int dir_row, int dirline);

private:
    class SpriteComponent* mSc;

    int mSound;
    //class Drop* mAboveDrop = nullptr;
    //class Drop* mBelowDrop = nullptr;
};


void ExchangeDrops(class Game* game, Drop* a, Drop* b);