#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;

	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Sandy the Worm", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/CourierPrime-Regular.ttf"))
	{
		std::cout << "ERROR > Game::initFonts::Failed to load font!" << "\n";
	}
}

void Game::initText()
{

}

void Game::initWorm()
{
	this->worm = new Worm(320.f, 440.f);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initWorm();
}

Game::~Game()
{
	delete this->window;
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateWorm()
{
	this->worm->update();
}

void Game::update()
{
	this->pollEvents();

	//this->updateText();

	if (!this->endGame)
	{
		//this->updateMousePositions();

		this->updateWorm();

		//this->updateEnemies();
	}
}

void Game::renderGui(sf::RenderTarget& target)
{

}

void Game::renderWorm(sf::RenderTarget& target)
{
	this->worm->render(target);
}

void Game::render()
{
	this->window->clear();

	this->renderGui(*this->window);

	this->renderWorm(*this->window);

	this->window->display();
}
