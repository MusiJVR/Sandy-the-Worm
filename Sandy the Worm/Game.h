#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

#include "Menu.h"
#include "Worm.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	Worm* worm;

	Menu* menu;

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mouseHeld;

	bool keyHeldA, keyHeldD, keyHeldW, keyHeldS;

	bool gameActive;
	bool sandBlockIsSpawned;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	sf::Texture groundTexture;
	sf::Sprite groundSprite;

	int selectedLevel;

	std::vector<std::vector<int>> mapSandBlocks;
	std::vector<std::vector<int>> mapLevelSandBlocks;
	std::vector<std::vector<bool>> supportedSandBlocks;
	std::vector<std::vector<bool>> sandBlocksOnWorm;

	/*int mapSandBlocks[12][20]{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};*/

	std::vector<SandBlock*> sandBlocks;
	std::vector<SandBlock*> levelSandBlocks;

	void initVariables();
	void initWindow();
	void initTexture();
	void initSprite();
	void initFonts();
	void initText();
	void initMenu();
	void initLevels();
	void initWorm();

public:
	//Constructors and Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool& getGameActive() const;
	void setGameActive(bool value);
	void resetKeys();

	//Modifiers

	//Functions
	const bool getWindowIsOpen() const;
	void pollEvents();
	bool getSandBlocksFallValues();
	bool getSandBlockSide(std::vector<std::vector<int>> map, bool side, int i, int j, int sizeMap, int axis);
	void dfs(int i, int j, const std::vector<std::vector<int>>& mapSandBlocks, std::vector<std::vector<bool>>& supportedSandBlocks);
	void setSupportedBlocks(std::vector<std::vector<int>>& mapSandBlocks, std::vector<std::vector<bool>>& supportedSandBlocks, std::vector<std::vector<bool>>& sandBlocksOnWorm);
	void dropUnsupportedBlocks(std::vector<std::vector<int>>& mapSandBlocks, const std::vector<std::vector<bool>>& supportedSandBlocks, std::vector<std::vector<bool>>& sandBlocksOnWorm);
	void spawnBlocks(std::vector<std::vector<int>> map, std::vector<SandBlock*> blocks, bool destructible, int x, int y);
	void moveIconLevels(int minIconLevel, int maxIconLevel, int resetIconLevel, int moveIconLevel, int extremeIconLevel, sf::Vector2f extremePosition, sf::Vector2f newPosition);
	bool wormIsFall(bool wormFalls, std::vector<SandBlock*> blocks, int x, int y, bool destructible);

	void updateInput();
	void updateMousePositions();
	void updateButtonScale(sf::Sprite& button, sf::Vector2f scale);
	void updatePressingButtons();
	void updateMenu();
	void updateWorm();
	void updateBlockSides(SandBlock* block, std::vector<std::vector<int>> map, int heightMap, int widthMap, int i, int j);
	void updateBlocks();
	void updateBlockDestruction();
	void updateFall();
	void update();

	void renderMenu(sf::RenderTarget& target);
	void renderGround(sf::RenderTarget& target);
	void renderWorm(sf::RenderTarget& target);
	void renderSandBlocks(sf::RenderTarget& target);
	void render();

	//Utils
	bool checkValidValue(int aLimit, int bLimit, int value);
};
