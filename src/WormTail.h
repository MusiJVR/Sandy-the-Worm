#pragma once

#include "TextureManager.h"

class WormTail
{
private:
	sf::Sprite sprite;

	sf::Vector2f followPosition;

	bool topSide, bottomSide, leftSide, rightSide;

	void initVariables();
	void initTexture();
	void initSprite();
	void initPosition(sf::Vector2f position, sf::Vector2f followPosition);

public:
	WormTail(sf::Vector2f position, sf::Vector2f followPosition);
	virtual ~WormTail();

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
