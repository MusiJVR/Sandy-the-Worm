#include <iostream>

#include "Game.h"

int WinMain()
{
	std::srand(static_cast<unsigned>(time(NULL)));

	Game game;

	while (game.getWindowIsOpen())
	{
		game.update();

		game.render();
	}

	return 0;
}
