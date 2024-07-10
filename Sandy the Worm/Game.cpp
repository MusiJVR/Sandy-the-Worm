#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;

	this->endGame = false;

	this->sandBlockIsSpawned = false;

	this->heightMap = 12;

	this->widthMap = 20;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Sandy the Worm", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}

void Game::initTexture()
{
	if (!this->groundTexture.loadFromFile("Textures/ground.png"))
	{
		std::cout << "ERROR > Game::initTexture::Could not load texture file." << "\n";
	}
}

void Game::initSprite()
{
	this->groundSprite.setTexture(this->groundTexture);
	this->groundSprite.setPosition(sf::Vector2f(0.f, 480.f));;
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
	this->worm = new Worm(sf::Vector2f(320.f, 440.f));
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTexture();
	this->initSprite();
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

void Game::spawnSandBlocks()
{
	bool topSide;
	bool bottomSide;
	bool leftSide;
	bool rightSide;

	unsigned i = 0;
	while (i < this->heightMap)
	{
		unsigned j = 0;
		while (j < this->widthMap)
		{
			if (this->mapSandBlocks[i][j] > 0)
			{
				topSide = false;
				bottomSide = false;
				leftSide = false;
				rightSide = false;

				//Top Side
				if (this->checkValidValue(0, this->heightMap, i - 1))
				{
					if (this->mapSandBlocks[i - 1][j] == 0)
					{
						topSide = true;
					}
				}
				else
				{
					topSide = true;
				}

				//Bottom Side
				if (this->checkValidValue(0, this->heightMap, i + 1))
				{
					if (this->mapSandBlocks[i + 1][j] == 0)
					{
						bottomSide = true;
					}
				}
				else
				{
					bottomSide = true;
				}

				//Left Side
				if (this->checkValidValue(0, this->widthMap, j - 1))
				{
					if (this->mapSandBlocks[i][j - 1] == 0)
					{
						leftSide = true;
					}
				}
				else
				{
					leftSide = true;
				}

				//Right Side
				if (this->checkValidValue(0, this->widthMap, j + 1))
				{
					if (this->mapSandBlocks[i][j + 1] == 0)
					{
						rightSide = true;
					}
				}
				else
				{
					rightSide = true;
				}

				this->sandBlocks.push_back(new SandBlock(sf::Vector2f((float)j * 40, (float)i * 40)));
				this->sandBlocks.back()->setSides(topSide, bottomSide, leftSide, rightSide);
			}
			j++;
		}
		i++;
	}

	this->sandBlockIsSpawned = true;
}

void Game::updateWorm()
{
	this->worm->update();
}

void Game::updateSandBlocks()
{
	if (!this->sandBlockIsSpawned)
	{
		this->spawnSandBlocks();
	}

	for (SandBlock* sandBlock : this->sandBlocks)
	{
		sandBlock->update();
	}
}

void Game::update()
{
	this->pollEvents();

	//this->updateText();

	if (!this->endGame)
	{
		//this->updateMousePositions();

		this->updateWorm();

		this->updateSandBlocks();
	}
}

void Game::renderGui(sf::RenderTarget& target)
{

}

void Game::renderGround(sf::RenderTarget& target)
{
	target.draw(this->groundSprite);
}

void Game::renderWorm(sf::RenderTarget& target)
{
	this->worm->render(target);
}

void Game::renderSandBlocks(sf::RenderTarget& target)
{
	for (SandBlock* sandBlock : this->sandBlocks)
	{
		sandBlock->render(target);
	}
}

void Game::render()
{
	this->window->clear();

	this->renderGui(*this->window);

	this->renderGround(*this->window);

	this->renderWorm(*this->window);

	this->renderSandBlocks(*this->window);

	this->window->display();
}

bool Game::checkValidValue(int aLimit, int bLimit, int value)
{
	if (value > aLimit && value < bLimit) return true;
	else return false;
}
