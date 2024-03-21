#pragma once

class Component
{
public:
	Component(class Actor* owner, int updateOrder = 100);
	virtual ~Component(){}

	virtual void ProcessInput(){}
	virtual void Update(){}
	
	int GetUpdateOrder() const { return mUpdateOrder; }

protected:

	class Actor* mOwner;
	int mUpdateOrder;
};
