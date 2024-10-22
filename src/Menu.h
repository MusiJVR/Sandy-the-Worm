#pragma once

#include "TextureManager.h"

class Menu
{
private:
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

	sf::Font font;
	sf::Text welcomeScreenText;

	bool welcomeScreenActive;

	void initVariables();
	void initFonts();
	void initText();
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
	std::vector<sf::Sprite*>& getAllIconLevels();
	std::vector<std::pair<int, sf::Sprite*>>& getShownIconLevels();

	void updateWelcomeScreen();
	void update();

	void renderText(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

