#include "../include/listeners.hpp"

int main() {
	Audo::Game* game = Audo::Game::GetInstance();

	game->updateEvent.Attach(update);
	game->inputEvent.Attach(input);
	game->drawEvent.Attach(draw);

	game->Run();
}