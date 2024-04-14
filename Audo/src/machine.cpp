#include "../include/machine.hpp"

Audo::Machine& Audo::Machine::Update() {
	// output items to connected machines
	OutputItem();
	return *this;
}

Audo::Machine& Audo::Machine::SetMachineList(std::vector<std::vector<Audo::Machine*>>* machines) {
	this->machines = machines;
	return *this;
}

Audo::Machine& Audo::Machine::Init(const int storageSize, const float speed, const MachineDirection dir) {
	this->clock.restart();
	this->storageSize = storageSize;
	this->speed = speed;

	return *this;
}

Audo::Machine& Audo::Machine::OutputItem() {
	for (int i = 0; i < 4; i++) {
		if (this->IO[i] == nullptr || this->IOType[i] != MachineIO::OUTPUT) {
			continue;
		}

		if (this->clock.getElapsedTime().asSeconds() < this->speed) {
			continue;
		}

		if (this->storage.empty()) {
			continue;
		}

		bool accepted = false;

		// check if the machine above can accept the item
		if (i == 0 && (this->IO[i]->IOCategory[1] == this->IOCategory[i] || this->IO[i]->IOCategory[1] == ItemCategory::ALL || (this->IOCategory[i] == ItemCategory::ALL && storage.front()->category == this->IO[i]->IOCategory[1])) && this->IO[i]->IOType[1] == MachineIO::INPUT) {
			accepted = true;
		}
		// check if the machine below can accept the item
		else if (i == 1 && (this->IO[i]->IOCategory[0] == this->IOCategory[i] || this->IO[i]->IOCategory[0] == ItemCategory::ALL || (this->IOCategory[i] == ItemCategory::ALL && storage.front()->category == this->IO[i]->IOCategory[0])) && this->IO[i]->IOType[0] == MachineIO::INPUT) {
			accepted = true;
		}
		// check if the machine to the left can accept the item
		else if (i == 2 && (this->IO[i]->IOCategory[3] == this->IOCategory[i] || this->IO[i]->IOCategory[3] == ItemCategory::ALL || (this->IOCategory[i] == ItemCategory::ALL && storage.front()->category == this->IO[i]->IOCategory[3])) && this->IO[i]->IOType[3] == MachineIO::INPUT) {
			accepted = true;
		}
		// check if the machine to the right can accept the item
		else if (i == 3 && (this->IO[i]->IOCategory[2] == this->IOCategory[i] || this->IO[i]->IOCategory[2] == ItemCategory::ALL || (this->IOCategory[i] == ItemCategory::ALL && storage.front()->category == this->IO[i]->IOCategory[2])) && this->IO[i]->IOType[2] == MachineIO::INPUT) {
			accepted = true;
		}

		if (!accepted) {
			continue;
		}

		if (this->IO[i]->storage.size() >= this->IO[i]->storageSize) {
			continue;
		}

		Item item = *this->storage.front();
		this->IO[i]->PushItem(item);
		this->PopItem();
		std::cout << "Item pushed\n";
	}
	return *this;
}

Audo::Machine& Audo::Machine::SetTexture(const std::string texturePath) {
	this->texture.loadFromFile(texturePath);
	return *this;
}

Audo::Machine& Audo::Machine::UpdateSprite() {
	this->sprite.setTexture(this->texture);
	return *this;
}

Audo::Machine& Audo::Machine::SetPosition(Vector2f position) {
	this->sprite.setPosition(position);
	// set map position
	this->machines->at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE)) = this;

	// update IO for machine above
	if (std::floor(position.y / TILE_SIZE) - 1 >= 0) {
		if (this->machines->at((int)std::floor(position.y / TILE_SIZE) - 1).at((int)std::floor(position.x / TILE_SIZE)) != nullptr) {
			this->machines->at((int)std::floor(position.y / TILE_SIZE) - 1).at((int)std::floor(position.x / TILE_SIZE))->UpdateIO(this, MachineDirection::DOWN);
			this->IO[0] = this->machines->at((int)std::floor(position.y / TILE_SIZE) - 1).at((int)std::floor(position.x / TILE_SIZE));
		}
	}

	// update IO for machine below
	if (std::floor(position.y / TILE_SIZE) + 1 < MAP_HEIGHT) {
		if (this->machines->at((int)std::floor(position.y / TILE_SIZE) + 1).at((int)std::floor(position.x / TILE_SIZE)) != nullptr) {
			this->machines->at((int)std::floor(position.y / TILE_SIZE) + 1).at((int)std::floor(position.x / TILE_SIZE))->UpdateIO(this, MachineDirection::UP);
			this->IO[1] = this->machines->at((int)std::floor(position.y / TILE_SIZE) + 1).at((int)std::floor(position.x / TILE_SIZE));
		}
	}

	// update IO for machine to the left
	if (std::floor(position.x / TILE_SIZE) - 1 >= 0) {
		if (this->machines->at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) - 1) != nullptr) {
			this->machines->at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) - 1)->UpdateIO(this, MachineDirection::RIGHT);
			this->IO[2] = this->machines->at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) - 1);
		}
	}

	// update IO for machine to the right
	if (std::floor(position.x / TILE_SIZE) + 1 < MAP_WIDTH) {
		if (this->machines->at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) + 1) != nullptr) {
			this->machines->at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) + 1)->UpdateIO(this, MachineDirection::LEFT);
			this->IO[3] = this->machines->at((int)std::floor(position.y / TILE_SIZE)).at((int)std::floor(position.x / TILE_SIZE) + 1);
		}
	}

	return *this;
}

Audo::Machine& Audo::Machine::SetIO(Machine* machine, const MachineDirection dir, const std::array<ItemCategory, 4> categories, const std::array<MachineIO, 4> types) {
	this->IO[(int)dir] = machine;

	for (int i = 0; i < 4; ++i) {
		this->IOCategory[i] = categories[i];
		this->IOType[i] = types[i];
	}

	return *this;
}

Audo::Machine& Audo::Machine::SetIO(Machine* machine, const MachineDirection dir) {
	this->IO[(int)dir] = machine;
	return *this;
}

Audo::Machine& Audo::Machine::SetIO(const std::array<ItemCategory, 4> categories, const std::array<MachineIO, 4> types) {
	for (int i = 0; i < 4; ++i) {
		this->IOCategory[i] = categories[i];
		this->IOType[i] = types[i];
	}

	return *this;
}

Audo::Machine& Audo::Machine::PushItem(const Item item) {
	if (this->storage.size() < this->storageSize) {
		if (this->storage.empty()) {
			this->clock.restart();
		}
		static Item* itemPtr = new Item(item);
		this->storage.push(itemPtr);
	}

	return *this;
}

Audo::Machine& Audo::Machine::PopItem() {
	if (!this->storage.empty()) {
		this->clock.restart();
		this->storage.pop();
	}

	return *this;
}

Audo::Machine& Audo::Machine::UpdateIO(Machine* machine, MachineDirection dir) {
	this->IO[(int)dir] = machine;

	return *this;
}