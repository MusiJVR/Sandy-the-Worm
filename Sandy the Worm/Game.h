#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

#include "Worm.h"
//#include "SandBlock.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	Worm* worm;

	bool endGame;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	//std::vector<SandBlock> sandBlock;

	void initVariables();
	void initWindow();
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

	void spawnSandBlock();
	void updateWorm();
	void updateCollision();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget& target);
	void renderWorm(sf::RenderTarget& target);
	void render();
};
