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
	sf::Texture texture;
	sf::Texture textureAngle;
	sf::Sprite sprite;

	sf::Vector2f followPosition;

	bool topSide;
	bool bottomSide;
	bool leftSide;
	bool rightSide;

	void initVariables();
	void initTexture();
	void initSprite();
	void initPosition(sf::Vector2f position, sf::Vector2f followPosition);

public:
	WormBody(sf::Vector2f position, sf::Vector2f followPosition);
	virtual ~WormBody();

	//Accessors
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	void moveSprite();
	void setFollowPosition(sf::Vector2f followPosition);

	//Functions
	bool getTopSide();
	bool getBottomSide();
	bool getLeftSide();
	bool getRightSide();
	void setSides(bool top, bool bottom, bool left, bool right);
	sf::Texture createTexture(std::string path);

	void updateRotation(bool top, bool bottom, bool left, bool right);
	void update();

	void render(sf::RenderTarget& target);
};
