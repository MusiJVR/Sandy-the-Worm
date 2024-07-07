#include "WormBody.h"

void WormBody::initVariables()
{
	this->topSide = true;
	this->bottomSide = true;
	this->leftSide = false;
	this->rightSide = false;
}

void WormBody::initTexture()
{
	if (!this->texture.loadFromFile("Textures/worm_body.png"))
	{
		std::cout << "ERROR > WormBody::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureAngle.loadFromFile("Textures/worm_body_angle.png"))
	{
		std::cout << "ERROR > WormBody::initTexture::Could not load texture file." << "\n";
	}
}

void WormBody::initSprite()
{
	this->sprite.setTexture(this->texture);
}

void WormBody::initPosition(sf::Vector2f position, sf::Vector2f followPosition)
{
	this->sprite.setOrigin(sprite.getTexture()->getSize().x * 0.5f, sprite.getTexture()->getSize().y * 0.5f);
	this->sprite.setPosition(position.x + sprite.getTexture()->getSize().x * 0.5f, position.y + sprite.getTexture()->getSize().y * 0.5f);

	this->setFollowPosition(followPosition);
}

WormBody::WormBody(sf::Vector2f position, sf::Vector2f followPosition)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initPosition(position, followPosition);
}

WormBody::~WormBody()
{

}

sf::Sprite WormBody::getSprite()
{
	return this->sprite;
}

sf::Vector2f WormBody::getPosition()
{
	return this->sprite.getPosition();
}

void WormBody::moveSprite()
{
	this->sprite.setPosition(this->followPosition);
}

void WormBody::setFollowPosition(sf::Vector2f followPosition)
{
	this->followPosition = followPosition;
}

bool WormBody::getTopSide()
{
	return this->topSide;
}

bool WormBody::getBottomSide()
{
	return this->bottomSide;
}

bool WormBody::getLeftSide()
{
	return this->leftSide;
}

bool WormBody::getRightSide()
{
	return this->rightSide;
}

void WormBody::setSides(bool top, bool bottom, bool left, bool right)
{
	this->topSide = top;
	this->bottomSide = bottom;
	this->leftSide = left;
	this->rightSide = right;
}

sf::Texture WormBody::createTexture(std::string path)
{
	sf::Texture texture;
	if (!this->texture.loadFromFile("Textures/" + path))
	{
		std::cout << "ERROR > WormBody::setTexture::Could not load texture file." << "\n";
	}
	return texture;
}

void WormBody::updateRotation(bool top, bool bottom, bool left, bool right)
{
	this->sprite.setTexture(this->texture);
	if (!top && !bottom && left && right)
	{
		this->sprite.setRotation(0.f);
	}
	else if (top && bottom && !left && !right)
	{
		this->sprite.setRotation(90.f);
	}
	else
	{
		this->sprite.setTexture(this->textureAngle);
		if (top && !bottom && !left && right)
		{
			this->sprite.setRotation(0.f);
		}
		else if (!top && bottom && !left && right)
		{
			this->sprite.setRotation(90.f);
		}
		else if (!top && bottom && left && !right)
		{
			this->sprite.setRotation(180.f);
		}
		else if (top && !bottom && left && !right)
		{
			this->sprite.setRotation(270.f);
		}
	}
}

void WormBody::update()
{
	this->updateRotation(this->getTopSide(), this->getBottomSide(), this->getLeftSide(), this->getRightSide());
}

void WormBody::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
