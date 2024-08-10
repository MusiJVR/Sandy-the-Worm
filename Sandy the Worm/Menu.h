#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Menu
{
private:
	sf::Texture textureWelcomeScreen,
		textureWelcomeTitle,
		textureButtonPlay,
		textureButtonSwitch,
		textureSelectedlvlFrame,
		textureIconlvl1,
		textureIconlvl2,
		textureIconlvl3,
		textureIconlvl4,
		textureIconlvl5,
		textureIconlvl6;
	sf::Sprite spriteWelcomeScreen,
		spriteWelcomeTitle,
		spriteButtonPlay,
		spriteFirstButtonSwitch,
		spriteSecondButtonSwitch,
		spriteSelectedlvlFrame,
		spriteIconlvl1,
		spriteIconlvl2,
		spriteIconlvl3,
		spriteIconlvl4,
		spriteIconlvl5,
		spriteIconlvl6;

	std::vector<sf::Sprite*> allIconLevels;
	std::vector<std::pair<int, sf::Sprite*>> shownIconLevels;

	bool welcomeScreenActive;
	bool gameStarted;

	void initVariables();
	void initTexture();
	void initSprite();
	void initPosition();

public:
	Menu();
	virtual ~Menu();

	//Accessors
	sf::Vector2f getTextureCenterCoordinates(sf::Sprite sprite);
	sf::Sprite& getSpriteButtonPlay();
	sf::Sprite& getSpriteFirstButtonSwitch();
	sf::Sprite& getSpriteSecondButtonSwitch();

	//Functions
	bool getWelcomeScreenActive();
	void setWelcomeScreenActive(bool value);
	bool getGameStarted();
	void setGameStarted(bool value);
	std::vector<sf::Sprite*>& getAllIconLevels();
	std::vector<std::pair<int, sf::Sprite*>>& getShownIconLevels();

	void updateWelcomeScreen();
	void update();

	void render(sf::RenderTarget& target);
};

