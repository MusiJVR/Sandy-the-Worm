#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

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

	bool topSide, bottomSide, leftSide, rightSide;

	void initVariables();
	void initTexture();
	void initSprite();
	void initPosition(sf::Vector2f position);

public:
	SandBlock(sf::Vector2f position);
	virtual ~SandBlock();

	//Accessors
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	void moveSprite(sf::Vector2f position);

	//Functions
	bool getTopSide();
	bool getBottomSide();
	bool getLeftSide();
	bool getRightSide();
	void setSides(bool top, bool bottom, bool left, bool right);

	void updateTexture(bool top, bool bottom, bool left, bool right);
	void update();

	void render(sf::RenderTarget& target);
};
