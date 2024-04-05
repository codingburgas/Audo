#pragma once
#include "raylib.h"
#include "cmath"

inline Vector2& operator+=(Vector2 vec1, const Vector2& vec2)
{
    vec1.x += vec2.y;
    vec1.y += vec2.y;

    return vec1;
}

inline Vector2& operator-=(Vector2 vec1, const Vector2& vec2) {
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;

    return vec1;
}

inline Vector2 operator/(const Vector2& vec, const float& num)
{
    return Vector2(vec.x / num, vec.y / num);
}

inline Vector2 operator*(const Vector2& vec, const float& num)
{
    return Vector2(vec.x * num, vec.y * num);
}

inline Vector2 operator-(const Vector2& vec1, const Vector2& vec2)
{
    return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
}

inline Vector2 operator+(const Vector2& vec1, const Vector2& vec2) {
    return Vector2(vec1.x + vec2.x, vec1.y + vec2.y);
}

namespace Audo::Utils
{

    inline Vector2 abs(const Vector2& vec)
    {
        return Vector2(std::abs(vec.x), std::abs(vec.y));
    }

    inline double magnitude(const Vector2& vec) {
        return std::hypotl(vec.x, vec.y);
    }

    inline Vector2 normalize(const Vector2& vec) {
        return vec / magnitude(vec);
    }
}

