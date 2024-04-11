#include "../include/listeners.hpp"

int main() {
	Audo::Game* game = Audo::Game::GetInstance();

	game->inputEvent.Attach(input);
	game->drawEvent.Attach(draw);

	game->Run();
}