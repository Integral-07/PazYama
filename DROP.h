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
    
    //Drop* GetAboveDrop() const { return mAboveDrop; }
    //void SetAboveDrop(class Drop* drop) { mAboveDrop = drop; }

    //Drop* GetBelowDrop() const { return mBelowDrop; }
    //void SetBelowDrop(class Drop* drop) { mBelowDrop = drop; }

public:
    enum DROP_KIND {
        NONE = -1,

        GRAPE,     //��
        PEACH,     //�s���N
        FUJI,      //��
        CRYSTAL,   //��
        PREFECTURE,//��
        HOTO,
        NUM_DROPS, //�h���b�v�̌�

        SENTINEL   //�ԕ�
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
    VECTOR2 mPositionOnBoard;    //�������{�[�h�̂ǂ̍s�E��ɂ��邩

    bool mSelectedFlag;
    bool mFallFlag;
    bool mAligned;
    bool mOldAligned;

    int CheckDir(int row, int line, int dir_row, int dirline);
    int CheckNone(int row, int line, int dir_row, int dirline);

private:
    class SpriteComponent* mSc;

    //class Drop* mAboveDrop = nullptr;
    //class Drop* mBelowDrop = nullptr;
};


void ExchangeDrops(class Game* game, Drop* a, Drop* b);