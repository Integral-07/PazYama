#include "VECTOR2.h"
#include "math.h"

VECTOR2::VECTOR2()
{
}

VECTOR2::VECTOR2(float _x, float _y)
	: x(_x), y(_y)
{
}

VECTOR2::VECTOR2(const VECTOR2& vec)
{
	this->x = vec.x;
	this->y = vec.y;
}

inline VECTOR2 VECTOR2::normalize(VECTOR2& vec)
{
	float root_len = vec.x * vec.x + vec.y * vec.y;
	return VECTOR2(vec.x / sqrt(root_len), vec.y / sqrt(root_len));
}

inline VECTOR2 VECTOR2::operator+(const VECTOR2& vec)
{
	return VECTOR2(this->x + vec.x, this->y + vec.y);
}

inline VECTOR2 VECTOR2::operator-(const VECTOR2& vec)
{
	return VECTOR2(this->x - vec.x, this->y - vec.y);
}

inline VECTOR2 VECTOR2::operator*(float k)
{
	return VECTOR2(this->x * k, this->y * k);
}

inline VECTOR2 VECTOR2::operator/(float k)
{
	return VECTOR2(this->x / k, this->y / k);
}

inline VECTOR2& VECTOR2::operator+=(const VECTOR2& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

inline VECTOR2& VECTOR2::operator-=(const VECTOR2& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

inline VECTOR2& VECTOR2::operator*=(float k)
{
	this->x *= k;
	this->y *= k;

	return *this;
}

inline VECTOR2& VECTOR2::operator/=(float k)
{
	this->x /= k;
	this->y /= k;

	return *this;
}
