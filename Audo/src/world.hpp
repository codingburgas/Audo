#pragma once
module;
#include "grand.h"
#include "PerlinNoise.hpp"
#include <string>
#include <utility>
#include <vector>

export module world;

#define MAP_HEIGHT 1024
#define MAP_WIDTH 1024


export namespace World {

	enum class TileType {
		WATER,
		GROUND,
		LITHIUM,
		GOLD,
		SILVER,
		BRONZE,
		ALUMINUM,
		CADMIUM,
		PALADIUM,
		URANIUM,
		PLATINUM
	};

	GRand gen;

	void GenerateWorld(std::vector<TileType>& map);
}