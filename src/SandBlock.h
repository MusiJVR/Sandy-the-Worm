#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class SandBlock
{
private:
	sf::Texture texture,
		textureTopLeft,
		textureLeft,
		textureBottomLeft,
		textureBottom,
		textureBottomRight,
		textureRight,
		textureTopRight,
		textureTop,
		textureTopBottom,
		textureLeftRight,
		textureTopBottomLeft,
		textureTopBottomRight,
		textureTopLeftRight,
		textureBottomLeftRight,
		textureTopBottomLeftRight;
	sf::Sprite sprite;

	bool topSide, bottomSide, leftSide, rightSide, sandBlockFalls, destructible;

	unsigned fallCounter;

	void initVariables(bool destructible);
	void initTexture();
	void initSprite();
	void initPosition(sf::Vector2f position);

public:
	SandBlock(bool destructible, sf::Vector2f position);
	virtual ~SandBlock();

	//Accessors
	sf::Vector2f getTextureCenterCoordinates(sf::Sprite sprite);
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	bool isDestructible();
	void moveSprite(sf::Vector2f position);

	//Functions
	void sandBlockFall();
	bool getFallValue();
	void setFallValue(bool value);
	bool getTopSide();
	bool getBottomSide();
	bool getLeftSide();
	bool getRightSide();
	void setSides(bool top, bool bottom, bool left, bool right);

	void updateTexture(bool top, bool bottom, bool left, bool right);
	void update();

	void render(sf::RenderTarget& target);
};
