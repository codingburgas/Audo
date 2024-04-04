#include <iostream>
#include "world.hpp"

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