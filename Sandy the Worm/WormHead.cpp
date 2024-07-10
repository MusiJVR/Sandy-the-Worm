#include "WormHead.h"

void WormHead::initVariables()
{
	this->topSide = true;
	this->bottomSide = true;
	this->leftSide = true;
	this->rightSide = false;
}

void WormHead::initTexture()
{
	if (!this->texture.loadFromFile("Textures/worm_head.png"))
	{
		std::cout << "ERROR > WormHead::initTexture::Could not load texture file." << "\n";
	}
}

void WormHead::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}

void WormHead::initPosition(sf::Vector2f position)
{
	this->sprite.setOrigin(this->sprite.getTexture()->getSize().x * 0.5f, this->sprite.getTexture()->getSize().y * 0.5f);
	this->sprite.setPosition(position.x + this->sprite.getTexture()->getSize().x * 0.5f, position.y + this->sprite.getTexture()->getSize().y * 0.5f);
}

WormHead::WormHead(sf::Vector2f position)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initPosition(position);
}

WormHead::~WormHead()
{

}

sf::Sprite WormHead::getSprite()
{
	return this->sprite;
}

sf::Vector2f WormHead::getPosition()
{
	return this->sprite.getPosition();
}

void WormHead::moveSprite(sf::Vector2f movePosition)
{
	this->sprite.move(movePosition);
}

bool WormHead::getTopSide()
{
	return this->topSide;
}

bool WormHead::getBottomSide()
{
	return this->bottomSide;
}

bool WormHead::getLeftSide()
{
	return this->leftSide;
}

bool WormHead::getRightSide()
{
	return this->rightSide;
}

void WormHead::setSides(bool top, bool bottom, bool left, bool right)
{
	this->topSide = top;
	this->bottomSide = bottom;
	this->leftSide = left;
	this->rightSide = right;
}

void WormHead::updateRotation(bool top, bool bottom, bool left, bool right)
{
	if (top && !bottom && left && right)
	{
		this->sprite.setRotation(0.f);
	}
	else if (top && bottom && !left && right)
	{
		this->sprite.setRotation(90.f);
	}
	else if (!top && bottom && left && right)
	{
		this->sprite.setRotation(180.f);
	}
	else if (top && bottom && left && !right)
	{
		this->sprite.setRotation(270.f);
	}
}

void WormHead::update()
{
	this->updateRotation(this->getTopSide(), this->getBottomSide(), this->getLeftSide(), this->getRightSide());
}

void WormHead::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
