#include "../include/game.hpp"

Audo::Game::Game() {
	// Initialize or set default values for your class members here
}

Audo::Game* Audo::Game::GetInstance() noexcept {
	std::lock_guard<std::mutex> lock(mutex);
	if (instance == nullptr) {
		instance = new Game();
	}
	return instance;
}

void Audo::Game::Init() noexcept {
	this->width = VideoMode::getDesktopMode().width;
	this->height = VideoMode::getDesktopMode().height;

	this->window.create(VideoMode(width, height), "fortnite", sf::Style::Fullscreen);
	//this->window.setFramerateLimit(60);

	this->camera.setCenter(14000, 14000);
	this->camera.setSize(this->width, this->height);
	this->camera.zoom(3.f);

	waterTexture.loadFromFile("./assets/water.png");

	deepWaterTexture.loadFromFile("./assets/deep_water.png");

	groundTexture.loadFromFile("./assets/grass.png");

	goldTexture.loadFromFile("./assets/gold.png");

	copperTexture.loadFromFile("./assets/copper.png");

	ironTexture.loadFromFile("./assets/iron.png");

	stoneTexture.loadFromFile("./assets/stone.png");

	darkStoneTexture.loadFromFile("./assets/dark_stone.png");

	snowTexture.loadFromFile("./assets/snow.png");

	textureMap[Audo::World::TileType::WATER] = waterTexture;
	textureMap[Audo::World::TileType::DEEP_WATER] = deepWaterTexture;
	textureMap[Audo::World::TileType::GROUND] = groundTexture;
	textureMap[Audo::World::TileType::GOLD] = goldTexture;
	textureMap[Audo::World::TileType::COPPER] = copperTexture;
	textureMap[Audo::World::TileType::IRON] = ironTexture;
	textureMap[Audo::World::TileType::STONE] = stoneTexture;
	textureMap[Audo::World::TileType::DARK_STONE] = darkStoneTexture;
	textureMap[Audo::World::TileType::SNOW] = snowTexture;

	Audo::World::GenerateWorld(this->map, this->textureMap);
}

void Audo::Game::Run() noexcept {
	std::unique_lock<std::mutex> lock(mutex);
		if (this->running) {
			return;
		}
		this->running = true;
	lock.unlock();

	Init();

	std::jthread updateThread(std::bind_front(&Game::Update, this));

	while (window.isOpen()) {
		HandleInput();
		Render();
		this->deltaTime = clock.getElapsedTime().asSeconds();
		//std::cout << 1.f / clock.getElapsedTime().asSeconds() << '\n';
		clock.restart();
	}

	updateThread.request_stop();
}

void Audo::Game::Update(std::stop_token sToken = {}) {
	double deltaTime = 0.0f;
	Clock updateClock;

	while (!sToken.stop_requested()) {
		deltaTime = updateClock.getElapsedTime().asSeconds();

		// refresh rate of UPDATE_RATE hz
		if (deltaTime < 1.f / UPDATE_RATE) {
			Audo::Utils::preciseSleep(1.f / UPDATE_RATE - deltaTime);
		}

		deltaTime = updateClock.getElapsedTime().asSeconds();

		// [TODO]
		// update objects

		updateClock.restart();
	}
}

void Audo::Game::Render() {
	this->window.setView(this->camera);
	this->window.clear(Color(45, 75, 118, 100));

	/*Vector2 startPosition = GetScreenToWorld2D({ 0,0 }, instance->camera);
	Vector2 endPosition = GetScreenToWorld2D({ (float)GetScreenWidth(), (float)GetScreenHeight() }, instance->camera);*/
	
	Vector2f startPosition = this->window.mapPixelToCoords({ 0, 0 });
	Vector2f endPosition = this->window.mapPixelToCoords(Vector2i(this->width, this->height));

	startPosition = Vector2f(std::clamp(startPosition.x, 0.f, (float)(MAP_WIDTH * TILE_SIZE)), std::clamp(startPosition.y, 0.f, (float)(MAP_HEIGHT * TILE_SIZE)));
	endPosition = Vector2f(std::clamp(endPosition.x, 0.f, (float)(MAP_WIDTH * TILE_SIZE)), std::clamp(endPosition.y, 0.f, (float)(MAP_HEIGHT * TILE_SIZE)));

	for (size_t i = startPosition.y / TILE_SIZE; i < endPosition.y / TILE_SIZE; ++i) {
		for (size_t j = startPosition.x / TILE_SIZE; j < endPosition.x / TILE_SIZE; ++j) {
			this->map[i][j]->draw(this->window);
		}
	}

	////for (auto* renderObject : this->renderObjects) {
	////	if (renderObject->shouldDraw) {
	////		renderObject->draw(this->window);
	////	}
	////}

	//this->window.setView(this->window.getDefaultView());
	this->window.display();
}

void Audo::Game::HandleInput() {
	sf::Event event;
	while (this->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			this->window.close();
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		camera.move(-900.f * this->deltaTime, 0);
	}

	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		camera.move(900.f * this->deltaTime, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		camera.move(0, -900.f * this->deltaTime);
	}

	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		camera.move(0, 900.f * this->deltaTime);
	}
}

Audo::Game* Audo::Game::instance{ nullptr };
std::mutex Audo::Game::mutex;
bool Audo::Game::running{ false };