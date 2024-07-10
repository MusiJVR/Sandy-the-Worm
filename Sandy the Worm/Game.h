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

	unsigned heightMap;
	unsigned widthMap;

	int mapSandBlocks[12][20]{
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
	};

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

	void spawnSandBlocks();
	void updateInput();
	void updateGui();
	void updateWorm();
	void updateSandBlocks();
	void updateFall();
	void update();

	void renderGui(sf::RenderTarget& target);
	void renderGround(sf::RenderTarget& target);
	void renderWorm(sf::RenderTarget& target);
	void renderSandBlocks(sf::RenderTarget& target);
	void render();

	//Utils
	bool checkValidValue(int aLimit, int bLimit, int value);
};
