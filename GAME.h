#define debug true

#pragma once
#include <vector>
#include "SpriteComponent.h"
#include "VECTOR2.h"
#include "Drop.h"

#define GameWidth 1000
#define GameHeight 1000
#define GameColor 32
#define GameTitle "�p�Y���}"
constexpr int PuzSize = 10;

class Game
{
public:

	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	enum GameState{

		ETitle, EPre, EPuz, EComb, EPaused, 
	};

	GameState GetGameState() const { return mGameState; }
	void SetGameState(GameState state) { mGameState = state; }

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	std::vector<class Actor*> mActors;
	std::vector<class SpriteComponent*> mSprites;

	bool mUpdatingActors;
	std::vector<class Actor*> mPendingActors; //�ǉ�����������Actor

	GameState mGameState;
public:
	void AddScore(int score);

	int GetKind(int row, int line) const { return mDrops[row][line]; }
	void SetKind(int row, int line, Drop::DROP_KIND kind) { mDrops[row][line] = kind; }

	
	Drop* GetAboveDrop(const VECTOR2& vec) const { return mDropsArray[(int)vec.x - 1][(int)vec.y]; }
	Drop* GetBelowDrop(const VECTOR2& vec) const { return mDropsArray[(int)vec.x + 1][(int)vec.y]; }
	Drop* GetRightDrop(const VECTOR2& vec) const { return mDropsArray[(int)vec.x][(int)vec.y + 1]; }
	Drop* GetLeftDrop(const VECTOR2& vec) const { return mDropsArray[(int)vec.x][(int)vec.y - 1]; }
	Drop* GetDrop(const VECTOR2& vec) const { return mDropsArray[(int)vec.x][(int)vec.y]; }
	void SetDrop(const VECTOR2& vec, Drop* drop) { mDropsArray[(int)vec.x][(int)vec.y] = drop; }
	void ExchangeDrops(const VECTOR2& a, const VECTOR2& b) {

		Drop* temp = mDropsArray[(int)a.x][(int)a.y];
		mDropsArray[(int)a.x][(int)a.y] = mDropsArray[(int)b.x][(int)b.y];
		mDropsArray[(int)b.x][(int)b.y] = temp;
	}

private:
	
	int mScore;

	int mDrops[PuzSize + 2][PuzSize + 2];
	Drop* mDropsArray[PuzSize + 2][PuzSize + 2];
};

