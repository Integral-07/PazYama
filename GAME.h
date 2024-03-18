#pragma once
#include <vector>
#include "SpriteComponent.h"

#define GameWidth 1000
#define GameHeight 1000
#define GameColor 32
#define GameTitle "�p�Y���}"
#define PuzSize 10

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
	std::vector<class Actor*> mPendingActors; //�ǉ�����������Actor


public:
	void AddScore(int score);

	void AddDrop(class Drop* drop);
	void RemoveDrop(class Drop* drop);
	std::vector<class Drop*>& GetDrop() { return mDrops; }

private:
	int mScore;

	std::vector<class Drop*> mDrops;
};

