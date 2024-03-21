#pragma once
#include "Actor.h"
#include "RectComponent.h"

class Drop :
    public Actor
{
public:
    Drop(class Game* game, int kind);

    void UpdateActor() override;
    void SetSpeed(float speed);
    void SetDirection(const VECTOR2& direction);
    void SetPositionOnBoard(const VECTOR2& pos) { mPositionOnBoard = pos; }

public:
    enum DROP_KIND {
        NONE = -1,

        GRAPE,     //��
        PEACH,     //�s���N
        FUJI,      //��
        CRYSTAL,   //��
        TEMP1,     //
        TEMP2,     //
        NUM_DROPS, //�h���b�v�̌�

        SENTINEL   //�ԕ�
    };

    const VECTOR2& GetPositionOnBoard() const { return mPositionOnBoard; }
    DROP_KIND GetKind() const { return mKindOfDrop; }
    void SetKind(int kind) { mKindOfDrop = (DROP_KIND)kind; }

    RectComponent* GetRect() const { return mRect; }
    

private:

    DROP_KIND mKindOfDrop;
    VECTOR2 mPositionOnBoard;    //�������{�[�h�̂ǂ̍s�E��ɂ��邩

    bool mSelectedFlag;
    bool mFallFlag;
    bool mAligned;

    int CheckDir(int row, int line, int dir_row, int dirline);
    bool IsAligned();

private:
    class RectComponent* mRect;

    class MoveComponent* mMc;
};

