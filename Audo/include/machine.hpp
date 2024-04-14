#pragma once
#include "renderobject.hpp"
#include "item.hpp"
#include <queue>
#include <iostream>

#define TILE_SIZE 100
#define MAP_WIDTH 1024
#define MAP_HEIGHT 1024

namespace Audo {
	enum class MachineType {
		CONVEYOR, 
		FORGE
	};

	enum class MachineDirection {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	enum class MachineIO {
		INPUT,
		OUTPUT,
		NONE
	};

	class Machine {
	protected:
		MachineType type;
		float speed;
		std::vector<std::vector<Machine*>>* machines;
		Sprite sprite;
		Texture texture;
		Clock clock;
		int storageSize;
		std::queue<Item*> storage;
		ItemCategory IOCategory[4];
		MachineIO IOType[4];

		// order of IO is UP, DOWN, LEFT, RIGHT
		Machine* IO[4] = { nullptr, nullptr, nullptr, nullptr };
		
		virtual Machine& UpdateIO(Machine* machine, MachineDirection dir);
		virtual Machine& OutputItem();
		
	public:
		virtual Machine& Init(const int storageSize, const float speed, const MachineDirection dir);

		virtual Machine& SetTexture(const std::string texturePath);

		virtual Machine& UpdateSprite();

		virtual Machine& SetPosition(const Vector2f position);
		
		// indexes correspond to UP, DOWN, LEFT, RIGHT
		virtual Machine& SetIO(Machine* machine, const MachineDirection dir, const std::array<ItemCategory, 4> categories, const std::array<MachineIO, 4> types);

		// indexes correspond to UP, DOWN, LEFT, RIGHT
		virtual Machine& SetIO(const std::array<ItemCategory, 4> categories, const std::array<MachineIO, 4> types);

		virtual Machine& SetIO(Machine* machine, const MachineDirection dir);

		virtual Machine& SetMachineList(std::vector<std::vector<Audo::Machine*>>* machines);

		virtual Machine& Update();

		virtual Machine& PushItem(const Item item);
		
		virtual Machine& PopItem();
	};
}