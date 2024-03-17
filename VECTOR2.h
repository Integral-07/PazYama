#pragma once
struct VECTOR2
{
	float x = 0.0f;
	float y = 0.0f;

	VECTOR2();
	VECTOR2(float _x, float _y);
	VECTOR2(const VECTOR2& vec);

	static VECTOR2 normalize(VECTOR2& vec);
	VECTOR2 operator+(const VECTOR2& vec);
	VECTOR2 operator-(const VECTOR2& vec);
	VECTOR2 operator*(float k);
	VECTOR2 operator/(float k);

	VECTOR2& operator+=(const VECTOR2& vec);
	VECTOR2& operator-=(const VECTOR2& vec);
	VECTOR2& operator*=(float k);
	VECTOR2& operator/=(float k);

};

