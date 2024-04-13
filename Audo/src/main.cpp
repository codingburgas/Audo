#include "../include/game.hpp"

int main() {
	Audo::Game* game = Audo::Game::GetInstance();

	game->Run();
}