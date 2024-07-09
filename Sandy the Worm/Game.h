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

	bool endGame;
	bool sandBlockIsSpawned;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	sf::Texture groundTexture;
	sf::Sprite groundSprite;

	//std::vector< std::vector<SandBlock*> > map;

	/*int mapSandBlocks[12][20]{
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};*/

	int mapSandBlocks[5][5]{
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 1, 1, 0},
		{0, 1, 1, 1, 0},
		{0, 1, 1, 1, 0}
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

	//Modifiers

	//Functions
	const bool getWindowIsOpen() const;
	void pollEvents();

	void spawnSandBlocks();
	void updateWorm();
	void updateSandBlocks();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget& target);
	void renderGround(sf::RenderTarget& target);
	void renderWorm(sf::RenderTarget& target);
	void renderSandBlocks(sf::RenderTarget& target);
	void render();

	//Utils
	bool checkValidValue(int aLimit, int bLimit, int value);
};
