#pragma once

#include "grand.h"
#include "PerlinNoise.hpp"
#include <string>
#include <utility>
#include <vector>


#define MAP_HEIGHT 1024
#define MAP_WIDTH 1024


namespace World {

	enum class TileType {
		WATER,
		DEEP_WATER,
		GROUND,
		LITHIUM,
		GOLD,
		SILVER,
		BRONZE,
		ALUMINUM,
		CADMIUM,
		PALADIUM,
		URANIUM,
		PLATINUM,
		COPPER,
		IRON,
		STONE,
		DARK_STONE,
		SNOW
	};

	static GRand gen = GRand();

	void GenerateWorld(std::vector<std::vector<World::TileType>>& map);
}