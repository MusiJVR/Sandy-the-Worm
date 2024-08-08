#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;

	this->mouseHeld = false;

	this->gameActive = false;

	this->sandBlockIsSpawned = false;

	this->mapSandBlocks = {
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1}
	};
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Sandy the Worm", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
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

void Game::initMenu()
{
	this->menu = new Menu();
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
	this->initMenu();
	this->initWorm();
}

Game::~Game()
{
	delete this->window;
}

const bool& Game::getGameActive() const
{
	return this->gameActive;
}

void Game::setGameActive(bool value)
{
	this->gameActive = value;
}

void Game::resetKeys()
{
	this->keyHeldA = false;
	this->keyHeldD = false;
	this->keyHeldW = false;
	this->keyHeldS = false;
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
			if (this->event.key.code == sf::Keyboard::Space)
				this->menu->setWelcomeScreenActive(false);
			break;
		}
	}
}

bool Game::getSandBlocksFallValues()
{
	for (SandBlock* sandBlock : this->sandBlocks)
	{
		if (sandBlock->getFallValue()) return true;
	}
	return false;
}

bool Game::getSandBlockSide(bool side, int i, int j, int sizeMap, int axis)
{
	if (this->checkValidValue(0, sizeMap - 1, axis))
	{
		if (this->mapSandBlocks[i][j] == 0)
		{
			side = true;
		}
	}
	else
	{
		side = true;
	}
	return side;
}

void Game::dfs(int i, int j, const std::vector<std::vector<int>>& mapSandBlocks, std::vector<std::vector<bool>>& boolMapSandBlocks)
{
	int rows = mapSandBlocks.size();
	int cols = mapSandBlocks[0].size();

	if (i < 0 || i >= rows || j < 0 || j >= cols || mapSandBlocks[i][j] == 0 || boolMapSandBlocks[i][j]) {
		return;
	}

	boolMapSandBlocks[i][j] = true;

	this->dfs(i + 1, j, mapSandBlocks, boolMapSandBlocks);
	this->dfs(i - 1, j, mapSandBlocks, boolMapSandBlocks);
	this->dfs(i, j + 1, mapSandBlocks, boolMapSandBlocks);
	this->dfs(i, j - 1, mapSandBlocks, boolMapSandBlocks);
}

void Game::setSupportedBlocks(std::vector<std::vector<int>>& mapSandBlocks, std::vector<std::vector<bool>>& supportedSandBlocks, std::vector<std::vector<bool>>& sandBlocksOnWorm)
{
	int rows = mapSandBlocks.size();
	int cols = mapSandBlocks[0].size();

	supportedSandBlocks = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
	sandBlocksOnWorm = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));

	for (int j = 0; j < cols; j++)
	{
		if (mapSandBlocks[rows - 1][j] == 1)
		{
			this->dfs(rows - 1, j, mapSandBlocks, supportedSandBlocks);
		}
	}

	for (SandBlock* sandBlock : this->sandBlocks)
	{
		if (((sandBlock->getPosition().y + 40.f == this->worm->getWormHead()->getPosition().y) && (sandBlock->getPosition().x == this->worm->getWormHead()->getPosition().x))
			|| ((sandBlock->getPosition().y + 40.f == this->worm->getWormBodyFirst()->getPosition().y) && (sandBlock->getPosition().x == this->worm->getWormBodyFirst()->getPosition().x))
			|| ((sandBlock->getPosition().y + 40.f == this->worm->getWormBodySecond()->getPosition().y) && (sandBlock->getPosition().x == this->worm->getWormBodySecond()->getPosition().x))
			|| ((sandBlock->getPosition().y + 40.f == this->worm->getWormTail()->getPosition().y) && (sandBlock->getPosition().x == this->worm->getWormTail()->getPosition().x)))
		{
			int i = (((int) sandBlock->getPosition().y - 20) / 40) - 7;
			int j = (((int) sandBlock->getPosition().x - 20) / 40) - 1;
			this->dfs(i, j, mapSandBlocks, sandBlocksOnWorm);
		}
	}
}

void Game::dropUnsupportedBlocks(std::vector<std::vector<int>>& mapSandBlocks, const std::vector<std::vector<bool>>& supportedSandBlocks, std::vector<std::vector<bool>>& sandBlocksOnWorm)
{
	int rows = mapSandBlocks.size();
	int cols = mapSandBlocks[0].size();

	for (int j = 0; j < cols; ++j)
	{
		for (int i = rows - 1; i >= 0; --i)
		{
			if (mapSandBlocks[i][j] == 1 && !supportedSandBlocks[i][j])
			{
				if (!sandBlocksOnWorm[i][j])
				{
					mapSandBlocks[i + 1][j] = 1;
					mapSandBlocks[i][j] = 0;
					for (SandBlock* sandBlock : this->sandBlocks)
					{
						if (sandBlock->getPosition() == sf::Vector2f((float)(((j + 1) * 40.f) + 20.f), (float)(((i + 7) * 40.f) + 20.f)))
						{
							sandBlock->setFallValue(true);
						}
					}
				}
			}
		}
	}
}

void Game::spawnSandBlocks()
{
	for (int i = 0; i < this->mapSandBlocks.size(); i++)
	{
		for (int j = 0; j < this->mapSandBlocks[0].size(); j++)
		{
			if (this->mapSandBlocks[i][j] > 0)
			{
				this->sandBlocks.push_back(new SandBlock(sf::Vector2f((float) (j + 1) * 40.f, (float) (i + 7) * 40.f)));
				this->updateSandBlockSides(this->sandBlocks.back(), this->mapSandBlocks.size(), this->mapSandBlocks[0].size(), i, j);
			}
		}
	}

	this->sandBlockIsSpawned = true;
}

void Game::updateInput()
{
	if (!this->worm->getFallValue() && !this->getSandBlocksFallValues())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (!this->keyHeldA)
			{
				this->keyHeldA = true;
				sf::Vector2f movePosition(-40.f, 0.f);
				if (this->worm->wormCanMove(this->worm->getWormHead()->getPosition() + movePosition))
				{
					this->worm->getWormHead()->moveSprite(movePosition);
					this->worm->getWormHead()->setSides(true, true, true, false);
					this->worm->moveWorm();

					std::cout << "A" << "\n";
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (!this->keyHeldD)
			{
				this->keyHeldD = true;
				sf::Vector2f movePosition(40.f, 0.f);
				if (this->worm->wormCanMove(this->worm->getWormHead()->getPosition() + movePosition))
				{
					this->worm->getWormHead()->moveSprite(movePosition);
					this->worm->getWormHead()->setSides(true, true, false, true);
					this->worm->moveWorm();

					std::cout << "D" << "\n";
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (!this->keyHeldW)
			{
				this->keyHeldW = true;
				sf::Vector2f movePosition(0.f, -40.f);
				if (this->worm->wormCanMove(this->worm->getWormHead()->getPosition() + movePosition))
				{
					this->worm->getWormHead()->moveSprite(movePosition);
					this->worm->getWormHead()->setSides(true, false, true, true);
					this->worm->moveWorm();

					std::cout << "W" << "\n";
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (!this->keyHeldS)
			{
				this->keyHeldS = true;
				sf::Vector2f movePosition(0.f, 40.f);
				if (this->worm->wormCanMove(this->worm->getWormHead()->getPosition() + movePosition))
				{
					this->worm->getWormHead()->moveSprite(movePosition);
					this->worm->getWormHead()->setSides(false, true, true, true);
					this->worm->moveWorm();

					std::cout << "S" << "\n";
				}
			}
		}
		else this->resetKeys();
	}
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateButtonScale(sf::Sprite& button, sf::Vector2f scale)
{
	if (button.getGlobalBounds().contains(this->mousePosView))
	{
		button.setScale(sf::Vector2f(scale.x * 1.1f, scale.y * 1.1f));
	}
	else
	{
		button.setScale(scale);
	}
}

void Game::updatePressingButtons()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!this->mouseHeld)
		{
			this->mouseHeld = true;
			if (this->menu->getSpriteButtonPlay().getGlobalBounds().contains(this->mousePosView))
			{
				this->menu->getSpriteButtonPlay().setScale(sf::Vector2f(1.f, 1.f));
				this->setGameActive(true);
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}

void Game::updateMenu()
{
	this->menu->update();

	if (!this->menu->getWelcomeScreenActive())
	{
		this->updateMousePositions();

		this->updateButtonScale(this->menu->getSpriteButtonPlay(), sf::Vector2f(1.f, 1.f));
		this->updateButtonScale(this->menu->getSpriteFirstButtonSwitch(), sf::Vector2f(1.f, 1.f));
		this->updateButtonScale(this->menu->getSpriteSecondButtonSwitch(), sf::Vector2f(-1.f, 1.f));

		this->updatePressingButtons();
	}
}

void Game::updateWorm()
{
	this->worm->update();
}

void Game::updateSandBlockSides(SandBlock* sandBlock, int heightMap, int widthMap, int i, int j)
{
	sandBlock->setSides(
		this->getSandBlockSide(false, i - 1, j, heightMap, i - 1),
		this->getSandBlockSide(false, i + 1, j, heightMap, i + 1),
		this->getSandBlockSide(false, i, j - 1, widthMap, j - 1),
		this->getSandBlockSide(false, i, j + 1, widthMap, j + 1)
	);
}

void Game::updateSandBlocks()
{
	if (!this->sandBlockIsSpawned)
	{
		this->spawnSandBlocks();
	}

	for (SandBlock* sandBlock : this->sandBlocks)
	{
		if (!this->getSandBlocksFallValues())
		{
			this->updateSandBlockSides(sandBlock, this->mapSandBlocks.size(), this->mapSandBlocks[0].size(), (((int)sandBlock->getPosition().y - 20) / 40) - 7, (((int)sandBlock->getPosition().x - 20) / 40) - 1);
		}
		
		sandBlock->update();
	}
}

void Game::updateFall()
{
	if (!this->worm->getFallValue())
	{
		bool wormIsFall = true;

		if (this->worm->getWormHead()->getPosition().y != 460.f
			&& this->worm->getWormBodyFirst()->getPosition().y != 460.f
			&& this->worm->getWormBodySecond()->getPosition().y != 460.f
			&& this->worm->getWormTail()->getPosition().y != 460.f)
		{
			for (SandBlock* sandBlock : this->sandBlocks)
			{

				int i = (((int) sandBlock->getPosition().y - 20) / 40) - 7;
				int j = (((int) sandBlock->getPosition().x - 20) / 40) - 1;

				//std::cout << "sand " << sandBlock->getPosition().x << " " << sandBlock->getPosition().y << "\n";
				//std::cout << "head " << this->worm->getWormHead()->getPosition().x << " " << this->worm->getWormHead()->getPosition().y << "\n";
				//std::cout << this->worm->getWormBodyFirst()->getPosition().x << " " << this->worm->getWormBodyFirst()->getPosition().y << "\n";
				//std::cout << this->worm->getWormBodySecond()->getPosition().x << " " << this->worm->getWormBodySecond()->getPosition().y << "\n";
				//std::cout << this->worm->getWormTail()->getPosition().x << " " << this->worm->getWormTail()->getPosition().y << "\n";

				if (this->supportedSandBlocks[i][j])
				{
					if ((this->worm->getWormHead()->getPosition().y + 40.f == sandBlock->getPosition().y) && (this->worm->getWormHead()->getPosition().x == sandBlock->getPosition().x))
					{
						wormIsFall = false;
						break;
					}
					else if (((this->worm->getWormBodyFirst()->getPosition().y + 40.f == sandBlock->getPosition().y) && (this->worm->getWormBodyFirst()->getPosition().x == sandBlock->getPosition().x))
						|| ((this->worm->getWormBodyFirst()->getPosition().y - 40.f == sandBlock->getPosition().y) && (this->worm->getWormBodyFirst()->getPosition().x == sandBlock->getPosition().x))
						|| ((this->worm->getWormBodyFirst()->getPosition().x + 40.f == sandBlock->getPosition().x) && (this->worm->getWormBodyFirst()->getPosition().y == sandBlock->getPosition().y))
						|| ((this->worm->getWormBodyFirst()->getPosition().x - 40.f == sandBlock->getPosition().x) && (this->worm->getWormBodyFirst()->getPosition().y == sandBlock->getPosition().y)))
					{
						wormIsFall = false;
						break;
					}
					else if (((this->worm->getWormBodySecond()->getPosition().y + 40.f == sandBlock->getPosition().y) && (this->worm->getWormBodySecond()->getPosition().x == sandBlock->getPosition().x))
						|| ((this->worm->getWormBodySecond()->getPosition().y - 40.f == sandBlock->getPosition().y) && (this->worm->getWormBodySecond()->getPosition().x == sandBlock->getPosition().x))
						|| ((this->worm->getWormBodySecond()->getPosition().x + 40.f == sandBlock->getPosition().x) && (this->worm->getWormBodySecond()->getPosition().y == sandBlock->getPosition().y))
						|| ((this->worm->getWormBodySecond()->getPosition().x - 40.f == sandBlock->getPosition().x) && (this->worm->getWormBodySecond()->getPosition().y == sandBlock->getPosition().y)))
					{
						wormIsFall = false;
						break;
					}
					else if ((this->worm->getWormTail()->getPosition().y + 40.f == sandBlock->getPosition().y) && (this->worm->getWormTail()->getPosition().x == sandBlock->getPosition().x))
					{
						wormIsFall = false;
						break;
					}
					else
					{
						wormIsFall = true;
					}
				}
			}
		}
		else
		{
			wormIsFall = false;
		}

		if (wormIsFall)
		{
			this->worm->setFallValue(true);
		}
	}

	if (!this->getSandBlocksFallValues())
	{
		this->setSupportedBlocks(this->mapSandBlocks, this->supportedSandBlocks, this->sandBlocksOnWorm);
		this->dropUnsupportedBlocks(this->mapSandBlocks, this->supportedSandBlocks, this->sandBlocksOnWorm);
	}
}

void Game::updateBlockDestruction()
{
	for (int i = 0; i < this->sandBlocks.size(); i++)
	{
		if (this->worm->getWormHead()->getPosition() == this->sandBlocks[i]->getPosition())
		{
			int iMap = (((int)this->sandBlocks[i]->getPosition().y - 20) / 40) - 7;
			int jMap = (((int)this->sandBlocks[i]->getPosition().x - 20) / 40) - 1;

			this->mapSandBlocks[iMap][jMap] = 0;

			this->sandBlocks.erase(this->sandBlocks.begin() + i);
		}
	}
}

void Game::update()
{
	this->pollEvents();

	//this->updateText();

	if (!this->gameActive)
	{
		this->updateMenu();

		if (this->menu->getGameStarted())
		{
			this->setGameActive(true);
		}
	}
	else
	{
		this->updateInput();

		this->updateWorm();

		this->updateSandBlocks();

		this->updateFall();

		this->updateBlockDestruction();
	}
}

void Game::renderMenu(sf::RenderTarget& target)
{
	this->menu->render(target);
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

	if (!this->gameActive)
	{
		this->renderMenu(*this->window);
	}
	else
	{
		this->renderGround(*this->window);

		this->renderWorm(*this->window);

		this->renderSandBlocks(*this->window);
	}
	
	this->window->display();
}

bool Game::checkValidValue(int aLimit, int bLimit, int value)
{
	if (value >= aLimit && value <= bLimit) return true;
	else return false;
}
