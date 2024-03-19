#pragma once
#include "Actor.h"
#include "Drop.h"
#include "Game.h"

class Board :
    public Actor
{
public:
    Board(class Game* game);

    void UpdateActor() override;
    
    void AddDrop(Drop* drop);
    void RemoveDrop(Drop* drop);

    void SetPosition(const VECTOR2& position) { mPosition = position; }

    void GenerateNoneAlignedBoard(); //�����ĂȂ��{�[�h�ɏC��
    
    /*���Ƃ�private*/void GenerateDropBoard();        //�h���b�v�̕��U�ۏ؂Ȃ��{�[�h����
private:
    bool IsAlign(bool isDelete);       //�����Ă锻��
    void GenerateNewDrop(int line, int kind);
    int CheckDir(int, int, int, int);
    
    void FillBlank();

    std::vector<class Drop*> mDropBoard;
    std::vector<int> mBlank;

    VECTOR2 mPosition;
};

