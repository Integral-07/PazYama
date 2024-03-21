#pragma once
#include "VECTOR2.h"
#include <vector>


class Actor
{
public:

	enum State {

		EActive, EPause, EOper, EDead
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

	float GetScaleW() const { return mScaleW; }
	float GetScaleH() const { return mScaleH; }
	void SetScaleW(float scale) { mScaleW = scale; }
	void SetScaleH(float scale) { mScaleH = scale; }

	class Game* GetGame() { return mGame; }

	void AddComponent(class Component*);
	void RemoveComponent(class Component*);

protected:
	State mState;

	VECTOR2 mPosition;
	float mScaleW;
	float mScaleH;

	class Game* mGame;

	std::vector<class Component*> mComponents;
};

