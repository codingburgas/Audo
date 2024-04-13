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
	//this->camera.zoom(3.f);
	this->zoom = 1.f;

	waterTexture.loadFromFile("./assets/water.png");
	waterTexture.setSmooth(true);

	deepWaterTexture.loadFromFile("./assets/deep_water.png");
	deepWaterTexture.setSmooth(true);

	groundTexture.loadFromFile("./assets/grass.png");
	groundTexture.setSmooth(true);

	goldTexture.loadFromFile("./assets/gold.png");
	goldTexture.setSmooth(true);

	copperTexture.loadFromFile("./assets/copper.png");
	copperTexture.setSmooth(true);

	ironTexture.loadFromFile("./assets/iron.png");
	ironTexture.setSmooth(true);

	stoneTexture.loadFromFile("./assets/stone.png");
	stoneTexture.setSmooth(true);

	darkStoneTexture.loadFromFile("./assets/dark_stone.png");
	darkStoneTexture.setSmooth(true);

	snowTexture.loadFromFile("./assets/snow.png");
	snowTexture.setSmooth(true);

	textureMap[Audo::World::TileType::WATER] = waterTexture;
	textureMap[Audo::World::TileType::DEEP_WATER] = deepWaterTexture;
	textureMap[Audo::World::TileType::GROUND] = groundTexture;
	textureMap[Audo::World::TileType::GOLD] = goldTexture;
	textureMap[Audo::World::TileType::COPPER] = copperTexture;
	textureMap[Audo::World::TileType::IRON] = ironTexture;
	textureMap[Audo::World::TileType::STONE] = stoneTexture;
	textureMap[Audo::World::TileType::DARK_STONE] = darkStoneTexture;
	textureMap[Audo::World::TileType::SNOW] = snowTexture;

	this->font.loadFromFile("./assets/fonts/Roboto-Black.ttf");
	this->fpsText.setFont(this->font);
	this->fpsText.setCharacterSize(48);
	this->fpsText.setFillColor(Color::White);
	this->fpsText.setPosition(10, 10);

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

		// uncomment for fps counter
		std::cout << 1.f / clock.getElapsedTime().asSeconds() << '\n';
		//this->fpsText.setString(std::to_string(1.f / clock.getElapsedTime().asSeconds()));

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

	this->window.setView(this->window.getDefaultView());
	this->window.draw(this->fpsText);
	this->window.display();
}

void Audo::Game::HandleInput() {
	sf::Event event;
	while (this->window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			this->window.close();
		}
		else if (event.type == Event::MouseWheelScrolled) {
			if (event.mouseWheelScroll.delta > 0 && this->zoom - 0.1 > 0.6) {
				this->zoom -= 0.1;
				this->camera.zoom(0.8f);
			}
			else if (event.mouseWheelScroll.delta < 0 && this->zoom + 0.1 < 1.4) {
				this->zoom += 0.1;
				this->camera.zoom(1.25f);
			}
		}
		else if (event.type == Event::MouseButtonPressed) {
			Vector2f mousePos = this->window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
			if (mousePos.x >= 0 && mousePos.x <= MAP_WIDTH * TILE_SIZE && mousePos.y >= 0 && mousePos.y <= MAP_HEIGHT * TILE_SIZE) {
				selectedTile = this->map[std::floor(mousePos.y / TILE_SIZE)][std::floor(mousePos.x / TILE_SIZE)];

				if (selectedTile->getType() == Audo::World::TileType::SNOW) {
					std::cout << "Snow\n";
				}
				else if (selectedTile->getType() == Audo::World::TileType::GROUND) {
					std::cout << "Ground\n";
				}
				else if (selectedTile->getType() == Audo::World::TileType::WATER) {
					std::cout << "Water\n";
				}
				else if (selectedTile->getType() == Audo::World::TileType::DEEP_WATER) {
					std::cout << "Deep Water\n";
				}
				else if (selectedTile->getType() == Audo::World::TileType::GOLD) {
					std::cout << "Gold\n";
				}
				else if (selectedTile->getType() == Audo::World::TileType::COPPER) {
					std::cout << "Copper\n";
				}
				else if (selectedTile->getType() == Audo::World::TileType::IRON) {
					std::cout << "Iron\n";
				}
				else if (selectedTile->getType() == Audo::World::TileType::STONE) {
					std::cout << "Stone\n";
				}
				else if (selectedTile->getType() == Audo::World::TileType::DARK_STONE) {
					std::cout << "Dark Stone\n";
				}
			}
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		camera.move(-900.f * this->deltaTime * (1 + zoom), 0);
	}

	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		camera.move(900.f * this->deltaTime * (1 + zoom), 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		camera.move(0, -900.f * this->deltaTime * (1 + zoom));
	}

	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		camera.move(0, 900.f * this->deltaTime * (1 + zoom));
	}

	if (camera.getCenter().x - camera.getSize().x / 2 < 0) {
		camera.setCenter(camera.getSize().x / 2, camera.getCenter().y);
	}
	else if (camera.getCenter().x + camera.getSize().x / 2 > MAP_WIDTH * TILE_SIZE) {
		camera.setCenter(MAP_WIDTH * TILE_SIZE - camera.getSize().x / 2, camera.getCenter().y);
	}
	if (camera.getCenter().y - camera.getSize().y / 2 < 0) {
		camera.setCenter(camera.getCenter().x, camera.getSize().y / 2);
	}
	else if (camera.getCenter().y + camera.getSize().y / 2 > MAP_HEIGHT * TILE_SIZE) {
		camera.setCenter(camera.getCenter().x, MAP_HEIGHT * TILE_SIZE - camera.getSize().y / 2);
	}

}

Audo::Game* Audo::Game::instance{ nullptr };
std::mutex Audo::Game::mutex;
bool Audo::Game::running{ false };