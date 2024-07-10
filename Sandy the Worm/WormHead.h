#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class WormHead
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	bool topSide, bottomSide, leftSide, rightSide;

	void initVariables();
	void initTexture();
	void initSprite();
	void initPosition(sf::Vector2f position);

public:
	WormHead(sf::Vector2f position);
	virtual ~WormHead();

	//Accessors
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	void moveSprite(sf::Vector2f movePosition);

	//Functions
	bool getTopSide();
	bool getBottomSide();
	bool getLeftSide();
	bool getRightSide();
	void setSides(bool top, bool bottom, bool left, bool right);

	void updateRotation(bool top, bool bottom, bool left, bool right);
	void update();

	void render(sf::RenderTarget& target);
};
