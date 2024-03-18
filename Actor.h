#pragma once
#include "VECTOR2.h"
#include <vector>


class Actor
{
public:

	enum State {

		EActive, EPause, EDead
	};

	Actor(class Game* game);
	virtual ~Actor();

	void ProcessInput();
	virtual void ActorInput(){}

	void Update();
	virtual void UpdateActor(){}


	// Setter/Getter
	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	const VECTOR2& GetPosition() const { return mPosition; }
	void SetPosition(const VECTOR2& pos) { mPosition = pos; }

	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }

	class Game* GetGame() { return mGame; }

	void AddComponent(class Component*);
	void RemoveComponent(class Component*);

protected:
	State mState;

	VECTOR2 mPosition;
	float mScale;

	class Game* mGame;

	std::vector<class Component*> mComponents;
};

