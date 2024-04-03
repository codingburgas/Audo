#include <iostream>
#include "PerlinNoise.hpp"
#include "world.hpp"

#define HEIGHT 1024
#define WIDTH 1024

int main() {

	std::vector<World::TileType> v;
	World::GenerateWorld(v);
	int counter = 0;
	for (auto c : v) {
		if (c == World::TileType::WATER)
			counter++;
	}
	std::cout << counter;
}