#pragma once
#include "math.h"
#include <chrono>
#include <thread>

namespace Audo::Utils
{

    inline Vector2f abs(const Vector2f& vec)
    {
        return Vector2f(std::abs(vec.x), std::abs(vec.y));
    }

    inline double magnitude(const Vector2f& vec) {
        return std::hypotl(vec.x, vec.y);
    }

    inline Vector2f normalize(const Vector2f& vec) {
        return vec / (float)magnitude(vec);
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
            this_thread::sleep_for(std::chrono::milliseconds(1));
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

