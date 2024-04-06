#pragma once
#include "raylib.h"
#include "math.h"
#include <chrono>
#include <thread>

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

    inline void preciseSleep(double seconds) {
        using namespace std;
        using namespace std::chrono;

        static double estimate = 5e-3;
        static double mean = 5e-3;
        static double m2 = 0;
        static int64_t count = 1;

        while (seconds > estimate) {
            auto start = high_resolution_clock::now();
            this_thread::sleep_for(milliseconds(1));
            auto end = high_resolution_clock::now();

            double observed = (end - start).count() / 1e9;
            seconds -= observed;

            ++count;
            double delta = observed - mean;
            mean += delta / count;
            m2 += delta * (observed - mean);
            double stddev = sqrt(m2 / (count - 1));
            estimate = mean + stddev;
        }

        // spin lock
        auto start = high_resolution_clock::now();
        while ((high_resolution_clock::now() - start).count() / 1e9 < seconds);
    }
}

