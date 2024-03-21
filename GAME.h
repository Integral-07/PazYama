#pragma once
#include <vector>
#include "SpriteComponent.h"
#include "Drop.h"

#define GameWidth 1000
#define GameHeight 1000
#define GameColor 32
#define GameTitle "ƒpƒYƒ„ƒ}"
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

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	std::vector<class Actor*> mActors;
	std::vector<class SpriteComponent*> mSprites;

	bool mUpdatingActors;
	std::vector<class Actor*> mPendingActors; //’Ç‰Á‚ð‰„Šú‚µ‚½Actor


public:
	void AddScore(int score);

	const std::vector<class Drop*>& GetDrops() const { return mDrops; }
	Drop* GetDrop(int row, int line) const { return mDrops[(PuzSize + 2) * row + line]; }
	void SetDrop(Drop* drop) { mDrops.emplace_back(drop); }
	void DeleteDrop(Drop* drop);

private:
	
	int mScore;
	std::vector<class Drop*> mDrops;
};

