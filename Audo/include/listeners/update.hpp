#pragma once
#include "../game.hpp"

void update(Audo::Game* instance, float deltaTime) {
    std::println("{0}", std::roundf((1.f / deltaTime) * 100.f) / 100.f);
}