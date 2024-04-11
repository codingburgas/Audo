#include "../include/world.hpp"

void Audo::World::GenerateWorld(std::vector<std::vector<Tile*>>& map, std::unordered_map<TileType, Texture>& textureMap) {
	siv::PerlinNoise::seed_type seed = World::gen.i(999999);

	int32_t octaves = (seed / 10000) % 100;

	double frequency = 6;

	octaves = std::clamp(octaves, 4, 5);

	siv::PerlinNoise perlin{ seed };

	double fx = (frequency / MAP_WIDTH);
	double fy = (frequency / MAP_HEIGHT);

	std::mutex mut;

	//Concurrency::parallel_for(0, MAP_HEIGHT, [&](int y) {
	//	std::vector<Tile*> v;
	//	Concurrency::parallel_for(0, MAP_WIDTH, [&](int x) {
	//		double noise = perlin.normalizedOctave2D((x * fx), (y * fy), octaves);

	//		if (noise >= 0.71 && noise < 0.76) {
	//			mut.lock();
	//			v.push_back(new Tile(TileType::WATER, textureMap, Vector2f{ (float)x * 100, (float)y * 100 }));
	//			mut.unlock();
	//		}
	//		else if (noise >= 0.76) {
	//			mut.lock();
	//			v.push_back(new Tile(TileType::DEEP_WATER, textureMap, Vector2f{ (float)x * 100, (float)y * 100 }));
	//			mut.unlock();
	//		}
	//		else if (noise < 0.71) {
	//			mut.lock();
	//			v.push_back(new Tile(TileType::GROUND, textureMap, Vector2f{ (float)x * 100, (float)y * 100 }));
	//			mut.unlock();
	//		}
	//	});

	//	mut.lock();
	//	map.push_back(v);
	//	mut.unlock();
	//});

	for (std::int32_t y = 0; y < MAP_HEIGHT; ++y) {
		std::vector<Tile*> v;
		for (std::int32_t x = 0; x < MAP_WIDTH; ++x) {
			double noise = perlin.octave2D_01((x * fx), (y * fy), octaves);

			if (noise >= 0.71 && noise < 0.76) {
				mut.lock();
				v.push_back(new Tile(TileType::WATER, textureMap, Vector2f{ (float)x * 100, (float)y * 100 }));
				mut.unlock();
			}
			else if (noise >= 0.76) {
				mut.lock();
				v.push_back(new Tile(TileType::DEEP_WATER, textureMap, Vector2f{ (float)x * 100, (float)y * 100 }));
				mut.unlock();
			}
			else if (noise < 0.71) {
				mut.lock();
				v.push_back(new Tile(TileType::GROUND, textureMap, Vector2f{ (float)x * 100, (float)y * 100 }));
				mut.unlock();
			}
		}

		mut.lock();
		map.push_back(v);
		mut.unlock();
	}

	perlin = siv::PerlinNoise{ seed + 2 };

	octaves = 12.5;
	frequency = 12.5;

	fx = (frequency / MAP_WIDTH);
	fy = (frequency / MAP_HEIGHT);

	mut.lock();
	mut.unlock();
	//Concurrency::parallel_for(0, MAP_HEIGHT, [&](int y) {
	//	Concurrency::parallel_for(0, MAP_WIDTH, [&](int x) {
	//		double noise = perlin.normalizedOctave2D((x * fx), (y * fy), octaves);
	//		if (noise < -0.30 && map[y][x]->getType() == TileType::GROUND)
	//			map[y][x]->setType(TileType::IRON, textureMap);
	//		else if (noise < 0.30 && noise >= 0.22 && map[y][x]->getType() == TileType::GROUND)
	//			map[y][x]->setType(TileType::STONE, textureMap);
	//		else if (noise >= 0.30 && noise < 0.36 && map[y][x]->getType() == TileType::GROUND)
	//			map[y][x]->setType(TileType::DARK_STONE, textureMap);
	//		else if (noise >= 0.36 && map[y][x]->getType() == TileType::GROUND)
	//			map[y][x]->setType(TileType::SNOW, textureMap);
	//	});
	//});

	for (std::int32_t y = 0; y < MAP_HEIGHT; ++y) {
		for (std::int32_t x = 0; x < MAP_WIDTH; ++x) {
			double noise = perlin.normalizedOctave2D((x * fx), (y * fy), octaves);
			if (noise < -0.30 && map[y][x]->getType() == TileType::GROUND)
				map[y][x]->setType(TileType::IRON, textureMap);
			else if (noise < 0.27 && noise >= 0.22 && map[y][x]->getType() == TileType::GROUND)
				map[y][x]->setType(TileType::STONE, textureMap);
			else if (noise >= 0.27 && noise < 0.33 && map[y][x]->getType() == TileType::GROUND)
				map[y][x]->setType(TileType::DARK_STONE, textureMap);
			else if (noise >= 0.33 && map[y][x]->getType() == TileType::GROUND)
				map[y][x]->setType(TileType::SNOW, textureMap);
		}
	}

	perlin = siv::PerlinNoise{ seed + 1 };

	octaves = 12.5;
	frequency = 75;

	fx = (frequency / MAP_WIDTH);
	fy = (frequency / MAP_HEIGHT);
	//Concurrency::parallel_for(0, MAP_HEIGHT, [&](int y) {
	//	Concurrency::parallel_for(0, MAP_WIDTH, [&](int x) {
	//		double noise = perlin.normalizedOctave2D((x * fx), (y * fy), octaves);
	//		if (noise >= 0.93 && map[y][x]->getType() == TileType::GROUND)
	//			map[y][x]->setType(TileType::GOLD, textureMap);
	//		else if (noise <= 0.10 && map[y][x]->getType() == TileType::GROUND)
	//			map[y][x]->setType(TileType::COPPER, textureMap);
	//	});
	//});

	for (std::int32_t y = 0; y < MAP_HEIGHT; ++y) {
		for (std::int32_t x = 0; x < MAP_WIDTH; ++x) {
			double noise = perlin.octave2D_01((x * fx), (y * fy), octaves);
			if (noise >= 0.93 && map[y][x]->getType() == TileType::GROUND)
				map[y][x]->setType(TileType::GOLD, textureMap);
			else if (noise <= 0.10 && map[y][x]->getType() == TileType::GROUND)
				map[y][x]->setType(TileType::COPPER, textureMap);
		}
	}

	std::cout << "Done generating world\n";
}

Audo::World::Tile::Tile(TileType type, std::unordered_map<TileType, Texture>& textureMap, Vector2f position) {
	setType(type, textureMap);
	this->sprite.setPosition(position);
}

void Audo::World::Tile::draw(RenderWindow& window) {
	window.draw(this->sprite);
}

Audo::World::TileType Audo::World::Tile::getType() const noexcept {
	return this->type;
}

void Audo::World::Tile::setType(TileType type, std::unordered_map<TileType, Texture>& textureMap) noexcept {
	this->type = type;
	this->sprite.setTexture(textureMap[type]);
}

Sprite& Audo::World::Tile::getSprite() noexcept {
	return this->sprite;
}