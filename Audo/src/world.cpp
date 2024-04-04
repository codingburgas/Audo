#include "world.hpp"

void World::GenerateWorld(std::vector<std::vector<World::TileType>>& map) {

	siv::PerlinNoise::seed_type seed = World::gen.i(999999);

	int32_t octaves = (seed / 10000) % 100;

	double frequency = 6;

	octaves = std::clamp(octaves, 4, 5);

	siv::PerlinNoise perlin{ seed };

	double fx = (frequency / MAP_WIDTH);
	double fy = (frequency / MAP_HEIGHT);

	double noise;
	for (std::int32_t y = 0; y < MAP_HEIGHT; ++y) {
		std::vector<World::TileType> v;
		for (std::int32_t x = 0; x < MAP_WIDTH; ++x) {
			noise = perlin.octave2D_01((x * fx), (y * fy), octaves);

			if (noise >= 0.71)
				v.push_back(TileType::WATER);
			else if (noise < 0.71)
				v.push_back(TileType::GROUND);
		}
		map.push_back(v);
	}

	perlin = siv::PerlinNoise{ seed + 2 };

	octaves = 12.5;
	frequency = 12.5;

	fx = (frequency / MAP_WIDTH);
	fy = (frequency / MAP_HEIGHT);
	for (std::int32_t y = 0; y < MAP_HEIGHT; ++y) {
		for (std::int32_t x = 0; x < MAP_WIDTH; ++x) {
			noise = perlin.normalizedOctave2D((x * fx), (y * fy), octaves);
			if (noise >= -0.5 && noise < -0.30 && map[y][x] == TileType::GROUND)
				map[y][x] = TileType::IRON;
			else if (noise < 0.5 && noise >= 0.24 && map[y][x] == TileType::GROUND)
				map[y][x] = TileType::STONE;
		}
	}

	perlin = siv::PerlinNoise{ seed + 1 };

	octaves = 12.5;
	frequency = 75;

	fx = (frequency / MAP_WIDTH);
	fy = (frequency / MAP_HEIGHT);
	for (std::int32_t y = 0; y < MAP_HEIGHT; ++y) {
		for (std::int32_t x = 0; x < MAP_WIDTH; ++x) {
			noise = perlin.octave2D_01((x * fx), (y * fy), octaves);
			if (noise >= 0.93 && map[y][x] == TileType::GROUND)
				map[y][x] = TileType::GOLD;
			else if (noise <= 0.10 && map[y][x] == TileType::GROUND)
				map[y][x] = TileType::COPPER;
		}
	}
}