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

	class Machine : public RenderObject {
	private:
		MachineType type;
		float speed;
		std::vector<std::vector<Machine*>>& machines;

		void UpdateIO(Machine* machine, MachineDirection dir);

	protected:
		Clock clock;
		int storageSize;
		std::queue<Item*> storage;
		ItemCategory IOCategory[4];
		MachineIO IOType[4];

		// order of IO is UP, DOWN, LEFT, RIGHT
		Machine* IO[4] = { nullptr, nullptr, nullptr, nullptr };
		
		void SetPosition(Vector2f position) override;
		
	public:
		Machine(int storageSize, float speed, MachineType type, MachineDirection dir, std::vector<std::vector<Audo::Machine*>>& machines, Vector2f position);

		
		// indexes correspond to UP, DOWN, LEFT, RIGHT
		void SetIO(Machine* machine, MachineDirection dir, std::array<ItemCategory, 4> categories, std::array<MachineIO, 4> types);

		// indexes correspond to UP, DOWN, LEFT, RIGHT
		void SetIO(std::array<ItemCategory, 4> categories, std::array<MachineIO, 4> types);

		void SetIO(Machine* machine, MachineDirection dir);

		void Update();

		void PushItem(Item item);

		void PopItem();

		void Cout() {
			std::cout << "Machine " << speed << '\n';
		}
	};
}