#include "../include/game.hpp"

Audo::Game::Game() {
	// Initialize or set default values for your class members here
}

Audo::Game* Audo::Game::GetInstance() noexcept {
	std::lock_guard<std::mutex> lock(mutex_);
	if (instance_ == nullptr) {
		instance_ = new Game();
	}
	return instance_;
}

void Audo::Game::Init() noexcept {

	this->camera = { 0 };
	this->camera.zoom = 0.36f;

	this->width = 1920;
	this->height = 1080;
	this->monitor = GetCurrentMonitor();

    this->cameraBounds = {
      19253.25f, 19104.75f, 18938.273438f, 18765.167969f, 18591.777344f,
      18396.193359f, 18189.298828f, 17976.751853f, 17764.203878f, 17469.074219f,
      17234.947266f, 16931.408203f, 16607.429688f, 16250.011719f, 15873.304688f,
      15479.590820f, 14998.400391f, 14502.624023f, 13959.341797f, 13323.376953f,
      12606.097656f, 11823.172852f, 10893.182617f, 9871.197266f, 8621.201172f,
      7165.808594f, 5383.988770f
    };

    this->cameraBoundsY = {
      22011.033203f, 21189.292969f, 19582.746094f, 15041.219727f
    };


	Audo::World::GenerateWorld(this->map);

}

void Audo::Game::Run() noexcept {
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
