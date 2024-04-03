#pragma once
#include "world.hpp"
void World::GenerateWorld(std::vector<TileType>& map) {

	siv::PerlinNoise::seed_type seed = gen.i(999999);


	int32_t octaves = (seed / 10000) % 100;

	double frequency = gen.d(10.0);

	frequency = std::clamp(frequency, 8.0, 8.0);

	octaves = std::clamp(octaves, 4, 5);

	const siv::PerlinNoise perlin{ seed };

	const double fx = (frequency / MAP_WIDTH);
	const double fy = (frequency / MAP_HEIGHT);
	double noise;
	for (std::int32_t y = 0; y < MAP_HEIGHT; ++y) {
		for (std::int32_t x = 0; x < MAP_WIDTH; ++x) {
			noise = perlin.octave2D_01((x * fx), (y * fy), octaves);
			if (noise <= 0.2)
				map.push_back(TileType::WATER);
			else {
				int ore = gen.i(8) + 2;
				map.push_back(static_cast<TileType>(ore));
			}

		}
	}

}