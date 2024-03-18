#include <math.h>
#include "VECTOR2.h"
VECTOR2::VECTOR2(float x, float y) {
    this->x = x;	this->y = y;
}
void VECTOR2::set(float x, float y) {
    this->x = x;    this->y = y;
}
VECTOR2 VECTOR2::operator+(const VECTOR2& v) const {
    return VECTOR2(x + v.x, y + v.y);
}
VECTOR2 VECTOR2::operator-(const VECTOR2& v) const {
    return VECTOR2(x - v.x, y - v.y);
}
VECTOR2 VECTOR2::operator*(float f) const {
    return VECTOR2(x * f, y * f);
}
VECTOR2 VECTOR2::operator/(float f) const {
    return VECTOR2(x / f, y / f);
}
VECTOR2 VECTOR2::operator-() const {
    return VECTOR2(-x, -y);
}
void VECTOR2::operator+=(const VECTOR2& v) {
    x += v.x;
    y += v.y;
}
void VECTOR2::operator-=(const VECTOR2& v) {
    x -= v.x;
    y -= v.y;
}
void VECTOR2::operator*=(float f) {
    x *= f;
    y *= f;
}
void VECTOR2::operator/=(float f) {
    x /= f;
    y /= f;
}

VECTOR2 VECTOR2::normalize() {
    float l = sqrtf(x * x + y * y);
    if (l != 0.0f) {
        x /= l;
        y /= l;
    }
    return VECTOR2(x, y);
}



//ÇQéüå≥ÉxÉNÉgÉãÇÃàÍî ä÷êî-------------------------------------------------------
VECTOR2 operator*(float f, const VECTOR2& v) {
    return VECTOR2(f * v.x, f * v.y);
}
VECTOR2 normalize(const VECTOR2& a) {
    float l = sqrtf(a.x * a.x + a.y * a.y);
    if (l != 0.0f)
        return VECTOR2(a.x / l, a.y / l);
    else
        return a;
}



