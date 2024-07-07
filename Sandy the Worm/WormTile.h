#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class WormTile
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	bool topSide;
	bool bottomSide;
	bool leftSide;
	bool rightSide;

	void initVariables();
	void initTexture();
	void initSprite();

public:
	WormTile();
	virtual ~WormTile();

	//Accessors
	sf::Sprite getSprite();

	//Functions
	bool getTopSide();
	bool getBottomSide();
	bool getLeftSide();
	bool getRightSide();

	void render(sf::RenderTarget& target);
};
