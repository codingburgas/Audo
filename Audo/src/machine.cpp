#include "../include/machine.hpp"

Audo::Machine::Machine(int storageSize, float speed, MachineType type, MachineDirection dir, std::vector<std::vector<Audo::Machine*>>& machines, Vector2f position) : storageSize(storageSize), speed(speed), type(type), machines(machines) {
	if (type == MachineType::CONVEYOR) {
		// set direction appropriately
	}

	SetPosition(position);

	this->clock.restart();
}

void Audo::Machine::Update() {
	// output items to connected machines
	for (int i = 0; i < 4; i++) {
		if (this->IO[i] == nullptr) {
			continue;
		}

		if (this->clock.getElapsedTime().asSeconds() < this->speed) {
			continue;
		}

		bool accepted = false;
		// check if the machine above can accept the item
		if (i == 0 && (this->IO[i]->IOCategory[1] == this->IOCategory[i] || this->IO[i]->IOCategory[1] == ItemCategory::ALL || (this->IOCategory[i] == ItemCategory::ALL && storage.front()->category == this->IO[i]->IOCategory[1])) && this->IO[i]->IOType[1] == MachineIO::INPUT) {
			accepted = true;
		}
		else if (i == 1 && (this->IO[i]->IOCategory[0] == this->IOCategory[i] || this->IO[i]->IOCategory[0] == ItemCategory::ALL || (this->IOCategory[i] == ItemCategory::ALL && storage.front()->category == this->IO[i]->IOCategory[0])) && this->IO[i]->IOType[0] == MachineIO::INPUT) {
			accepted = true;
		}
		else if (i == 2 && (this->IO[i]->IOCategory[3] == this->IOCategory[i] || this->IO[i]->IOCategory[3] == ItemCategory::ALL || (this->IOCategory[i] == ItemCategory::ALL && storage.front()->category == this->IO[i]->IOCategory[3])) && this->IO[i]->IOType[3] == MachineIO::INPUT) {
			accepted = true;
		}
		else if (i == 3 && (this->IO[i]->IOCategory[2] == this->IOCategory[i] || this->IO[i]->IOCategory[2] == ItemCategory::ALL || (this->IOCategory[i] == ItemCategory::ALL && storage.front()->category == this->IO[i]->IOCategory[2])) && this->IO[i]->IOType[2] == MachineIO::INPUT) {
			accepted = true;
		}

		if (!accepted) {
			continue;
		}
		//std::cout << "Item accepted\n";


		if (this->IO[i]->storage.size() >= this->IO[i]->storageSize) {
			continue;
		}
		else if (this->IO[i]->storage.size() == 0) {
			this->IO[i]->clock.restart();
		}


		if (!this->storage.empty()) {
			Item item = *this->storage.front();
			this->IO[i]->PushItem(item);
			this->PopItem();
			std::cout << "Item pushed\n";
			this->clock.restart();
		}
	}
}

void Audo::Machine::SetPosition(Vector2f position) {
	this->sprite.setPosition(position);

	// set map position
	this->machines[(int)std::floor(position.y / TILE_SIZE)][(int)std::floor(position.x / TILE_SIZE)] = this;

	// update IO for machine above
	if (std::floor(position.y / TILE_SIZE) - 1 >= 0) {
		if (this->machines.at((int)std::floor(position.y / TILE_SIZE) - 1).at((int)std::floor(position.x / TILE_SIZE)) != nullptr) {
			this->machines.at((int)std::floor(position.y / TILE_SIZE) - 1).at((int)std::floor(position.x / TILE_SIZE))->UpdateIO(this, MachineDirection::DOWN);
		}
	}

	// update IO for machine below
	if (std::floor(position.y / TILE_SIZE) + 1 < MAP_HEIGHT) {
		if (this->machines.at((int)std::floor(position.y / TILE_SIZE) + 1).at((int)std::floor(position.x / TILE_SIZE)) != nullptr) {
			this->machines.at((int)std::floor(position.y / TILE_SIZE) + 1).at((int)std::floor(position.x / TILE_SIZE))->UpdateIO(this, MachineDirection::UP);
		}
	}

	// update IO for machine to the left
	if (std::floor(position.x / TILE_SIZE) - 1 >= 0) {
		if (this->machines.at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) - 1) != nullptr) {
			this->machines.at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) - 1)->UpdateIO(this, MachineDirection::RIGHT);
		}
	}

	// update IO for machine to the right
	if (std::floor(position.x / TILE_SIZE) + 1 < MAP_WIDTH) {
		if (this->machines.at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) + 1) != nullptr) {
			this->machines.at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) + 1)->UpdateIO(this, MachineDirection::LEFT);
		}
	}
}

void Audo::Machine::SetIO(Machine* machine, MachineDirection dir, std::array<ItemCategory, 4> categories, std::array<MachineIO, 4> types) {
	this->IO[(int)dir] = machine;

	for (int i = 0; i < 4; ++i) {
		this->IOCategory[i] = categories[i];
		this->IOType[i] = types[i];
	}
}

void Audo::Machine::SetIO(Machine* machine, MachineDirection dir) {
	this->IO[(int)dir] = machine;
}

void Audo::Machine::SetIO(std::array<ItemCategory, 4> categories, std::array<MachineIO, 4> types) {
	for (int i = 0; i < 4; ++i) {
		this->IOCategory[i] = categories[i];
		this->IOType[i] = types[i];
	}
}

void Audo::Machine::PushItem(Item item) {
	if (this->storage.size() < this->storageSize) {
		static Item* itemPtr = new Item(item);
		this->storage.push(itemPtr);
	}
}

void Audo::Machine::PopItem() {
	if (!this->storage.empty()) {
		this->storage.pop();
	}
}

void Audo::Machine::UpdateIO(Machine* machine, MachineDirection dir) {
	this->IO[(int)dir] = machine;
}