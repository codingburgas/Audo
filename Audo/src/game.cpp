#include "../include/game.hpp"

Audo::Game::Game() {
	// Initialize or set default values for your class members here
}

Audo::Game* Audo::Game::GetInstance() {
	std::lock_guard<std::mutex> lock(mutex_);
	if (instance_ == nullptr) {
		instance_ = new Game();
	}
	return instance_;
}

void Audo::Game::Init() {
	this->camera = { 0 };
	this->camera.zoom = 0.36f;

	this->width = 1920;
	this->height = 1080;
	this->monitor = GetCurrentMonitor();

	Audo::World::GenerateWorld(this->map);
}

void Audo::Game::Run() {
	std::unique_lock<std::mutex> lock(mutex_);
	if (this->running_) {
		return;
	}
	this->running_ = true;

	lock.unlock();

	Init();

	InitWindow(this->width, this->height, "fortnite");

	while (!WindowShouldClose()) {
		this->updateEvent.Invoke(instance_);

		this->drawEvent.Invoke(instance_);
	}
}

Audo::Game* Audo::Game::instance_{ nullptr };
std::mutex Audo::Game::mutex_;
bool Audo::Game::running_{ false };
