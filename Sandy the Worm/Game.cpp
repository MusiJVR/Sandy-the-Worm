#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;

	this->mouseHeld = false;

	this->gameActive = false;

	this->spawnActive = false;

	this->youWonActive = false;

	this->selectedLevel = 1;

	this->youWonTitleCounter = 0;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Sandy the Worm", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initAudioManager()
{
	this->audioManager = new AudioManager();

	this->audioManager->playMusic("Sounds/alienblues.ogg", 50.0f, true);
	this->audioManager->loadSound("button_click", "Sounds/button_click.wav");
	this->audioManager->loadSound("you_won", "Sounds/you_won.wav");
	this->audioManager->loadSound("worm_crawl", "Sounds/worm_crawl.wav");
	this->audioManager->loadSound("sand_break", "Sounds/sand_break.wav");
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/PressStart2P-Regular.ttf"))
	{
		std::cout << "ERROR > Game::initFonts::Failed to load font!" << "\n";
	}
}

void Game::initText()
{
	this->menuText.setFont(this->font);
	this->menuText.setCharacterSize(20);
	this->menuText.setFillColor(sf::Color(211, 27, 89));
	this->menuText.setString("Menu: M");

	this->readyText.setFont(this->font);
	this->readyText.setCharacterSize(20);
	this->readyText.setFillColor(sf::Color(211, 27, 89));
	this->readyText.setString("Ready: O");

	this->resetText.setFont(this->font);
	this->resetText.setCharacterSize(20);
	this->resetText.setFillColor(sf::Color(211, 27, 89));
	this->resetText.setString("Reset: R");

	float indentation = (800 - this->menuText.getGlobalBounds().width - this->readyText.getGlobalBounds().width - this->resetText.getGlobalBounds().width) / 4;

	this->menuText.setPosition(sf::Vector2f((float)indentation, 530.f));
	this->readyText.setPosition(sf::Vector2f((float)indentation * 2 + this->menuText.getGlobalBounds().width, 530.f));
	this->resetText.setPosition(sf::Vector2f((float)indentation * 3 + this->menuText.getGlobalBounds().width + this->readyText.getGlobalBounds().width, 530.f));
}

void Game::initTexture()
{
	if (!this->backgroundTexture.loadFromFile("Textures/background.png"))
	{
		std::cout << "ERROR > Game::initTexture::Could not load texture file." << "\n";
	}

	if (!this->youWonTitleTexture.loadFromFile("Textures/you_won_title.png"))
	{
		std::cout << "ERROR > Game::initTexture::Could not load texture file." << "\n";
	}
}

void Game::initSprite()
{
	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setPosition(sf::Vector2f(0.f, 0.f));;

	this->youWonTitleSprite.setTexture(this->youWonTitleTexture);
	this->youWonTitleSprite.setOrigin(this->getTextureCenterCoordinates(this->youWonTitleSprite));
	this->youWonTitleSprite.setPosition(sf::Vector2f(0.f, 0.f) + this->getTextureCenterCoordinates(this->youWonTitleSprite));
}

void Game::initMenu()
{
	this->menu = new Menu();
}

void Game::initLevels()
{
	this->mapSandBlocks = {
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1}
	};

	switch (this->selectedLevel)
	{
	case 1:
		this->mapLevelSandBlocks = {
			{0, 1, 1, 1, 0},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0}
		};
		break;
	case 2:
		this->mapLevelSandBlocks = {
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{1, 1, 1, 1, 1},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0}
		};
		break;
	case 3:
		this->mapLevelSandBlocks = {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 1, 1, 0},
			{1, 1, 1, 1, 1}
		};
		break;
	case 4:
		this->mapLevelSandBlocks = {
			{0, 0, 0, 0, 1},
			{0, 0, 0, 1, 1},
			{0, 1, 1, 1, 0},
			{0, 1, 0, 0, 0},
			{1, 1, 0, 0, 0}
		};
		break;
	case 5:
		this->mapLevelSandBlocks = {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 1, 1, 0},
			{0, 1, 0, 1, 0},
			{0, 1, 1, 1, 0}
		};
		break;
	case 6:
		this->mapLevelSandBlocks = {
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0}
		};
		break;
	default:
		this->mapLevelSandBlocks = {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		};
		break;
	}
}

void Game::initWorm()
{
	this->worm = new Worm(sf::Vector2f(320.f, 440.f));
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initAudioManager();
	this->initFonts();
	this->initText();
	this->initTexture();
	this->initSprite();
	this->initMenu();
	this->initWorm();
}

Game::~Game()
{
	delete this->audioManager;
	delete this->window;
}

AudioManager* Game::getAudioManager()
{
	return this->audioManager;
}

sf::Vector2f Game::getTextureCenterCoordinates(sf::Sprite sprite)
{
	return sf::Vector2f(sprite.getTexture()->getSize().x * 0.5f, sprite.getTexture()->getSize().y * 0.5f);
}

bool Game::getGameActive()
{
	return this->gameActive;
}

void Game::setGameActive(bool value)
{
	this->gameActive = value;
}

bool Game::getSpawnActive()
{
	return this->spawnActive;
}

void Game::setSpawnActive(bool value)
{
	this->spawnActive = value;
}

bool Game::getYouWonActive()
{
	return this->youWonActive;
}

void Game::setYouWonActive(bool value)
{
	this->youWonActive = value;
}

void Game::resetMapsAndBlocks()
{
	std::vector<std::vector<int>>().swap(this->mapSandBlocks);
	std::vector<std::vector<int>>().swap(this->mapLevelSandBlocks);
	std::vector<SandBlock*>().swap(this->sandBlocks);
	std::vector<SandBlock*>().swap(this->levelSandBlocks);
}

void Game::resetKeysWASD()
{
	this->keyHeldA = false;
	this->keyHeldD = false;
	this->keyHeldW = false;
	this->keyHeldS = false;
}

void Game::resetKeysMOR()
{
	this->keyHeldM = false;
	this->keyHeldO = false;
	this->keyHeldR = false;
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
			{
				this->window->close();
			}
			if (this->event.key.code == sf::Keyboard::Space && this->menu->getWelcomeScreenActive())
			{
				this->audioManager->playSound("button_click");
				this->menu->setWelcomeScreenActive(false);
			}
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

bool Game::getSandBlockSide(std::vector<std::vector<int>> map, bool side, int i, int j, int sizeMap, int axis)
{
	if (this->checkValidValue(0, sizeMap - 1, axis))
	{
		if (map[i][j] == 0)
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

void Game::spawnBlocks(std::vector<std::vector<int>>& map, std::vector<SandBlock*>& blocks, bool destructible, int x, int y)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] > 0)
			{
				blocks.push_back(new SandBlock(destructible, sf::Vector2f((float) (j + x) * 40.f, (float) (i + y) * 40.f)));
			}
		}
	}
}

void Game::moveIconLevels(int minIconLevel, int maxIconLevel, int resetIconLevel, int moveIconLevel, int extremeIconLevel, sf::Vector2f extremePosition, sf::Vector2f newPosition)
{
	if (minIconLevel >= maxIconLevel)
	{
		this->selectedLevel = resetIconLevel;
	}
	else
	{
		this->selectedLevel += moveIconLevel;
	}

	std::vector<std::pair<int, sf::Sprite*>> newShownIconLevels(5, { 0, nullptr });

	for (auto icon : this->menu->getShownIconLevels())
	{
		if (icon.second->getPosition() == extremePosition)
		{
			if (this->menu->getShownIconLevels()[extremeIconLevel].first == this->menu->getAllIconLevels().size() - resetIconLevel)
			{
				newShownIconLevels[extremeIconLevel] = { resetIconLevel - 1, this->menu->getAllIconLevels()[resetIconLevel - 1] };
			}
			else
			{
				newShownIconLevels[extremeIconLevel] = { this->menu->getShownIconLevels()[extremeIconLevel].first + moveIconLevel, this->menu->getAllIconLevels()[this->menu->getShownIconLevels()[extremeIconLevel].first + moveIconLevel] };
			}

			newShownIconLevels[extremeIconLevel].second->setPosition(newPosition + this->menu->getTextureCenterCoordinates(*newShownIconLevels[extremeIconLevel].second));
		}
		else
		{
			icon.second->move(sf::Vector2f((float) -98.f * moveIconLevel, 0.f));

			int& key = icon.first;
			auto iter = std::find_if(this->menu->getShownIconLevels().begin(), this->menu->getShownIconLevels().end(),
				[&key](const std::pair<int, sf::Sprite*>& pair) {
					return pair.first == key;
				});
			int index = std::distance(this->menu->getShownIconLevels().begin(), iter);

			newShownIconLevels[index - moveIconLevel] = icon;
		}
	}
	this->menu->getShownIconLevels() = newShownIconLevels;
	std::vector<std::pair<int, sf::Sprite*>>().swap(newShownIconLevels);
}

bool Game::wormIsFall(bool wormFalls, std::vector<SandBlock*> blocks, int x, int y, bool destructible)
{
	for (SandBlock* block : blocks)
	{
		int i = (((int)block->getPosition().y - 20) / 40) - y;
		int j = (((int)block->getPosition().x - 20) / 40) - x;

		if (this->supportedSandBlocks[i][j] || !destructible)
		{
			if ((this->worm->getWormHead()->getPosition().y + 40.f == block->getPosition().y) && (this->worm->getWormHead()->getPosition().x == block->getPosition().x))
			{
				wormFalls = false;
				break;
			}
			else if (((this->worm->getWormBodyFirst()->getPosition().y + 40.f == block->getPosition().y) && (this->worm->getWormBodyFirst()->getPosition().x == block->getPosition().x))
				|| ((this->worm->getWormBodyFirst()->getPosition().y - 40.f == block->getPosition().y) && (this->worm->getWormBodyFirst()->getPosition().x == block->getPosition().x))
				|| ((this->worm->getWormBodyFirst()->getPosition().x + 40.f == block->getPosition().x) && (this->worm->getWormBodyFirst()->getPosition().y == block->getPosition().y))
				|| ((this->worm->getWormBodyFirst()->getPosition().x - 40.f == block->getPosition().x) && (this->worm->getWormBodyFirst()->getPosition().y == block->getPosition().y)))
			{
				wormFalls = false;
				break;
			}
			else if (((this->worm->getWormBodySecond()->getPosition().y + 40.f == block->getPosition().y) && (this->worm->getWormBodySecond()->getPosition().x == block->getPosition().x))
				|| ((this->worm->getWormBodySecond()->getPosition().y - 40.f == block->getPosition().y) && (this->worm->getWormBodySecond()->getPosition().x == block->getPosition().x))
				|| ((this->worm->getWormBodySecond()->getPosition().x + 40.f == block->getPosition().x) && (this->worm->getWormBodySecond()->getPosition().y == block->getPosition().y))
				|| ((this->worm->getWormBodySecond()->getPosition().x - 40.f == block->getPosition().x) && (this->worm->getWormBodySecond()->getPosition().y == block->getPosition().y)))
			{
				wormFalls = false;
				break;
			}
			else if ((this->worm->getWormTail()->getPosition().y + 40.f == block->getPosition().y) && (this->worm->getWormTail()->getPosition().x == block->getPosition().x))
			{
				wormFalls = false;
				break;
			}
			else
			{
				wormFalls = true;
			}
		}
	}

	return wormFalls;
}

void Game::updateInput()
{
	if (!this->worm->getFallValue() && !this->getSandBlocksFallValues() && !this->getYouWonActive())
	{
		std::vector<SandBlock*> allBlocks;
		allBlocks.insert(allBlocks.end(), this->sandBlocks.begin(), this->sandBlocks.end());
		allBlocks.insert(allBlocks.end(), this->levelSandBlocks.begin(), this->levelSandBlocks.end());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (!this->keyHeldA)
			{
				this->keyHeldA = true;
				sf::Vector2f movePosition(-40.f, 0.f);
				if (this->worm->wormCanMove(allBlocks, this->worm->getWormHead()->getPosition() + movePosition))
				{
					this->audioManager->playSound("worm_crawl");
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
				if (this->worm->wormCanMove(allBlocks, this->worm->getWormHead()->getPosition() + movePosition))
				{
					this->audioManager->playSound("worm_crawl");
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
				if (this->worm->wormCanMove(allBlocks, this->worm->getWormHead()->getPosition() + movePosition))
				{
					this->audioManager->playSound("worm_crawl");
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
				if (this->worm->wormCanMove(allBlocks, this->worm->getWormHead()->getPosition() + movePosition))
				{
					this->audioManager->playSound("worm_crawl");
					this->worm->getWormHead()->moveSprite(movePosition);
					this->worm->getWormHead()->setSides(false, true, true, true);
					this->worm->moveWorm();

					std::cout << "S" << "\n";
				}
			}
		}
		else this->resetKeysWASD();

		std::vector<SandBlock*>().swap(allBlocks);
	}

	if (this->getGameActive())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			if (!this->keyHeldM)
			{
				this->keyHeldM = true;
				this->audioManager->playSound("button_click");
				this->initMenu();
				this->selectedLevel = 1;
				this->setGameActive(false);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			if (!this->keyHeldO)
			{
				this->keyHeldO = true;
				this->audioManager->playSound("button_click");
				if (this->mapSandBlocks == this->mapLevelSandBlocks)
				{
					this->audioManager->playSound("you_won");
					this->setYouWonActive(true);
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			if (!this->keyHeldR)
			{
				this->keyHeldR = true;
				this->audioManager->playSound("button_click");
				this->setSpawnActive(true);
			}
		}
		else this->resetKeysMOR();
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
				this->audioManager->playSound("button_click");
				this->menu->getSpriteButtonPlay().setScale(sf::Vector2f(1.f, 1.f));

				this->setGameActive(true);
				this->setSpawnActive(true);

				std::cout << "Level selected: " << this->selectedLevel << "\n\n";
			}
			else if (this->menu->getSpriteFirstButtonSwitch().getGlobalBounds().contains(this->mousePosView))
			{
				this->audioManager->playSound("button_click");
				this->moveIconLevels(this->selectedLevel, this->menu->getAllIconLevels().size(), 1, 1, 4, sf::Vector2f(204.f, 213.f), sf::Vector2f(558.f, 175.f));
			}
			else if (this->menu->getSpriteSecondButtonSwitch().getGlobalBounds().contains(this->mousePosView))
			{
				this->audioManager->playSound("button_click");
				this->moveIconLevels(1, this->selectedLevel, this->menu->getAllIconLevels().size(), -1, 0, sf::Vector2f(596.f, 213.f), sf::Vector2f(166.f, 175.f));
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

void Game::updateBlockSides(SandBlock* block, std::vector<std::vector<int>> map, int heightMap, int widthMap, int i, int j)
{
	block->setSides(
		this->getSandBlockSide(map, false, i - 1, j, heightMap, i - 1),
		this->getSandBlockSide(map, false, i + 1, j, heightMap, i + 1),
		this->getSandBlockSide(map, false, i, j - 1, widthMap, j - 1),
		this->getSandBlockSide(map, false, i, j + 1, widthMap, j + 1)
	);
}

void Game::updateBlocks()
{
	if (this->getSpawnActive())
	{
		this->resetMapsAndBlocks();

		this->initLevels();

		this->spawnBlocks(this->mapSandBlocks, this->sandBlocks, true, 1, 7);
		this->spawnBlocks(this->mapLevelSandBlocks, this->levelSandBlocks, false, 14, 7);

		this->initWorm();

		this->setSpawnActive(false);
	}

	for (SandBlock* sandBlock : this->sandBlocks)
	{
		if (!this->getSandBlocksFallValues())
		{
			this->updateBlockSides(sandBlock, this->mapSandBlocks, this->mapSandBlocks.size(), this->mapSandBlocks[0].size(), (((int)sandBlock->getPosition().y - 20) / 40) - 7, (((int)sandBlock->getPosition().x - 20) / 40) - 1);
		}
		
		sandBlock->update();
	}

	for (SandBlock* levelSandBlock : this->levelSandBlocks)
	{
		if (!this->getSandBlocksFallValues())
		{
			this->updateBlockSides(levelSandBlock, this->mapLevelSandBlocks, this->mapLevelSandBlocks.size(), this->mapLevelSandBlocks[0].size(), (((int)levelSandBlock->getPosition().y - 20) / 40) - 7, (((int)levelSandBlock->getPosition().x - 20) / 40) - 14);
		}

		levelSandBlock->update();
	}
}

void Game::updateFall()
{
	if (!this->worm->getFallValue())
	{
		bool wormFalls = true;

		if (this->worm->getWormHead()->getPosition().y != 460.f
			&& this->worm->getWormBodyFirst()->getPosition().y != 460.f
			&& this->worm->getWormBodySecond()->getPosition().y != 460.f
			&& this->worm->getWormTail()->getPosition().y != 460.f)
		{
			if (!this->wormIsFall(wormFalls, this->sandBlocks, 1, 7, true) || !this->wormIsFall(wormFalls, this->levelSandBlocks, 14, 7, false))
			{
				wormFalls = false;
			}
		}
		else
		{
			wormFalls = false;
		}

		if (wormFalls)
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

			this->audioManager->playSound("sand_break");
		}
	}
}

void Game::update()
{
	this->pollEvents();

	if (!this->getGameActive())
	{
		this->updateMenu();
	}
	else
	{
		if (!this->getYouWonActive())
		{
			this->updateInput();

			this->updateBlocks();

			this->updateWorm();

			this->updateBlockDestruction();

			this->updateFall();
		}
	}
}

void Game::renderMenu(sf::RenderTarget& target)
{
	this->menu->render(target);
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->menuText);
	target.draw(this->readyText);
	target.draw(this->resetText);
}

void Game::renderBackground(sf::RenderTarget& target)
{
	target.draw(this->backgroundSprite);
}

void Game::renderYouWonTitle(sf::RenderTarget& target)
{
	target.draw(this->youWonTitleSprite);
}

void Game::renderWorm(sf::RenderTarget& target)
{
	this->worm->render(target);
}

void Game::renderBlocks(sf::RenderTarget& target)
{
	for (SandBlock* sandBlock : this->sandBlocks)
	{
		sandBlock->render(target);
	}

	for (SandBlock* levelSandBlock : this->levelSandBlocks)
	{
		levelSandBlock->render(target);
	}
}

void Game::render()
{
	this->window->clear();

	if (!this->getGameActive())
	{
		this->renderMenu(*this->window);
	}
	else
	{
		this->renderBackground(*this->window);

		this->renderText(*this->window);

		this->renderWorm(*this->window);

		this->renderBlocks(*this->window);

		if (this->getYouWonActive())
		{
			this->renderYouWonTitle(*this->window);

			this->youWonTitleCounter++;

			if (this->youWonTitleCounter % 40 % 5 == 0)
			{
				if (this->youWonTitleCounter % 40 < 21 && this->youWonTitleCounter % 40 != 0)
				{
					this->youWonTitleSprite.setScale(this->youWonTitleSprite.getScale() + sf::Vector2f(0.1f, 0.1f));
				}
				else if (this->youWonTitleCounter % 40 > 20 || this->youWonTitleCounter % 40 == 0)
				{
					this->youWonTitleSprite.setScale(this->youWonTitleSprite.getScale() - sf::Vector2f(0.1f, 0.1f));
				}
			}

			if (this->youWonTitleCounter >= 200)
			{
				this->youWonTitleCounter = 0;
				this->setYouWonActive(false);

				this->initMenu();
				this->selectedLevel = 1;
				this->setGameActive(false);
			}
		}
	}
	
	this->window->display();
}

bool Game::checkValidValue(int aLimit, int bLimit, int value)
{
	if (value >= aLimit && value <= bLimit) return true;
	else return false;
}
