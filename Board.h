#pragma once
#include "Actor.h"
#include "Drop.h"
#include "Game.h"

#if 0
class Board :
    public Actor
{
public:
    Board(class Game* game);

    void UpdateActor() override;
    
    void AddDrop(Drop* drop);
    void RemoveDrop(Drop* drop);

    void SetPosition(const VECTOR2& position) { mPosition = position; }

    void GenerateNoneAlignedBoard(); //揃ってないボードに修正
    
private:
    bool IsAlign(bool isDelete);       //揃ってる判定
    void GenerateNewDrop(int line, int kind);
    int CheckDir(int, int, int, int);
    
    void FillBlank();

    std::vector<class Drop*> mDropBoard;
    std::vector<int> mBlank;

    VECTOR2 mPosition;
};

#endif