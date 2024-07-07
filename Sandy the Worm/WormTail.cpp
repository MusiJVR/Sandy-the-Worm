#include "WormTail.h"

void WormTail::initVariables()
{
	this->topSide = true;
	this->bottomSide = true;
	this->leftSide = false;
	this->rightSide = true;
}

void WormTail::initTexture()
{
	if (!this->texture.loadFromFile("Textures/worm_tail.png"))
	{
		std::cout << "ERROR > WormTail::initTexture::Could not load texture file." << "\n";
	}
}

void WormTail::initSprite()
{
	this->sprite.setTexture(this->texture);
}

void WormTail::initPosition(sf::Vector2f position, sf::Vector2f followPosition)
{
	this->sprite.setOrigin(sprite.getTexture()->getSize().x * 0.5f, sprite.getTexture()->getSize().y * 0.5f);
	this->sprite.setPosition(position.x + sprite.getTexture()->getSize().x * 0.5f, position.y + sprite.getTexture()->getSize().y * 0.5f);

	this->setFollowPosition(followPosition);
}

WormTail::WormTail(sf::Vector2f position, sf::Vector2f followPosition)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initPosition(position, followPosition);
}

WormTail::~WormTail()
{

}

sf::Sprite WormTail::getSprite()
{
	return this->sprite;
}

sf::Vector2f WormTail::getPosition()
{
	return this->sprite.getPosition();
}

void WormTail::moveSprite()
{
	this->sprite.setPosition(this->followPosition);
}

void WormTail::setFollowPosition(sf::Vector2f followPosition)
{
	this->followPosition = followPosition;
}

bool WormTail::getTopSide()
{
	return this->topSide;
}

bool WormTail::getBottomSide()
{
	return this->bottomSide;
}

bool WormTail::getLeftSide()
{
	return this->leftSide;
}

bool WormTail::getRightSide()
{
	return this->rightSide;
}

void WormTail::setSides(bool top, bool bottom, bool left, bool right)
{
	this->topSide = top;
	this->bottomSide = bottom;
	this->leftSide = left;
	this->rightSide = right;
}

void WormTail::updateRotation(bool top, bool bottom, bool left, bool right)
{
	if (!top && bottom && left && right)
	{
		this->sprite.setRotation(0.f);
	}
	else if (top && bottom && left && !right)
	{
		this->sprite.setRotation(90.f);
	}
	else if (top && !bottom && left && right)
	{
		this->sprite.setRotation(180.f);
	}
	else if (top && bottom && !left && right)
	{
		this->sprite.setRotation(270.f);
	}
}

void WormTail::update()
{
	this->updateRotation(this->getTopSide(), this->getBottomSide(), this->getLeftSide(), this->getRightSide());
}

void WormTail::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
