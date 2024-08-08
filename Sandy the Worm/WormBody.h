#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class WormBody
{
private:
	sf::Texture texture, textureAngle;
	sf::Sprite sprite;

	sf::Vector2f followPosition;

	bool topSide, bottomSide, leftSide, rightSide;

	void initVariables();
	void initTexture();
	void initSprite();
	void initPosition(sf::Vector2f position, sf::Vector2f followPosition);

public:
	WormBody(sf::Vector2f position, sf::Vector2f followPosition);
	virtual ~WormBody();

	//Accessors
	sf::Vector2f getTextureCenterCoordinates(sf::Sprite sprite);
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	void moveSprite(sf::Vector2f movePosition);
	void setFollowPosition();
	void resetFollowPosition(sf::Vector2f followPosition);

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
