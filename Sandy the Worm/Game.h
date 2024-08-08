#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

#include "Worm.h"
#include "SandBlock.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	Worm* worm;

	bool keyHeldA, keyHeldD, keyHeldW, keyHeldS;

	bool endGame;
	bool sandBlockIsSpawned;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	sf::Texture groundTexture;
	sf::Sprite groundSprite;

	std::vector<std::vector<int>> mapSandBlocks;
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

	void initVariables();
	void initWindow();
	void initTexture();
	void initSprite();
	void initFonts();
	void initText();
	void initWorm();

public:
	//Constructors and Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool& getEndGame() const;
	void resetKeys();

	//Modifiers

	//Functions
	const bool getWindowIsOpen() const;
	void pollEvents();
	bool getSandBlocksFallValues();
	bool getSandBlockSide(bool side, int i, int j, int sizeMap, int axis);
	void dfs(int i, int j, const std::vector<std::vector<int>>& mapSandBlocks, std::vector<std::vector<bool>>& supportedSandBlocks);
	void setSupportedBlocks(std::vector<std::vector<int>>& mapSandBlocks, std::vector<std::vector<bool>>& supportedSandBlocks, std::vector<std::vector<bool>>& sandBlocksOnWorm);
	void dropUnsupportedBlocks(std::vector<std::vector<int>>& mapSandBlocks, const std::vector<std::vector<bool>>& supportedSandBlocks, std::vector<std::vector<bool>>& sandBlocksOnWorm);

	void spawnSandBlocks();
	void updateInput();
	void updateGui();
	void updateWorm();
	void updateSandBlockSides(SandBlock* sandBlock, int heightMap, int widthMap, int i, int j);
	void updateSandBlocks();
	void updateFall();
	void updateBlockDestruction();
	void update();

	void renderGui(sf::RenderTarget& target);
	void renderGround(sf::RenderTarget& target);
	void renderWorm(sf::RenderTarget& target);
	void renderSandBlocks(sf::RenderTarget& target);
	void render();

	//Utils
	bool checkValidValue(int aLimit, int bLimit, int value);
};
