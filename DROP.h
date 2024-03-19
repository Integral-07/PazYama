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

    bool EnableToDrop();  //������锻��
    
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
private:

    DROP_KIND mKindOfDrop;
    VECTOR2 mPositionOnBoard;    //�������{�[�h�̂ǂ̍s�E��ɂ��邩

    bool mSelected;

private:
    class RectComponent* mRect;

    class MoveComponent* mMc;
};

