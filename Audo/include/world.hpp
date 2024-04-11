#pragma once

#include "grand.h"
#include "PerlinNoise.hpp"
#include "renderobject.hpp"
#include <string>
#include <utility>
#include <vector>
#include <ppl.h>
#include <iostream>

#define MAP_HEIGHT 1024
#define MAP_WIDTH 1024

namespace Audo {
	namespace World {
		enum class TileType {
			NONE,
			WATER,
			DEEP_WATER,
			GROUND,
			GOLD,
			COPPER,
			IRON,
			STONE,
			DARK_STONE,
			SNOW
		};

		class Tile {
		private:
			TileType type;
			Sprite sprite;
		public:
			Tile(TileType type, std::unordered_map<TileType, Texture>& textureMap, Vector2f position);

			void draw(RenderWindow& window);

			[[nodiscard]]
			TileType getType() const noexcept;

			[[nodiscard]]
			Sprite& getSprite() noexcept;

			void setType(TileType type, std::unordered_map<TileType, Texture>& textureMap) noexcept;
		};

		static GRand gen = GRand();

		void GenerateWorld(std::vector<std::vector<Tile*>>& map, std::unordered_map<TileType, Texture>& textureMap);
	}
}