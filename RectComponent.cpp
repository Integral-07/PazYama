#include "RectComponent.h"
#include "Actor.h"

RectComponent::RectComponent(Actor* owner, int order)
	: Component(owner, order), mHalfWidth(0.0f), mHalfHeight(0.0f)
{
}

const VECTOR2& RectComponent::GetCenter() const
{
	return mOwner->GetPosition() + mOwner->GetPosition() / 2;
}

bool Intersect(const RectComponent* a, const RectComponent* b)
{
	VECTOR2 diff = (a->GetCenter() - b->GetCenter());
	float ww = a->GetHalfWidth() + b->GetHalfWidth();
	if (abs(diff.x) < ww) {

		float hh = a->GetHalfHeight() + b->GetHalfHeight();
		if (abs(diff.y) < hh) {

			return true;
		}
	}

	return false;
}
