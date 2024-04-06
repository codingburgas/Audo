#include "../include/listeners.hpp"

int main() {
	Audo::Game* game = Audo::Game::GetInstance();

	game->updateEvent.Attach(update);
	game->drawEvent.Attach(draw);

	game->Run();
}