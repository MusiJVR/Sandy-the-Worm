#include "SandBlock.h"

void SandBlock::initVariables(bool destructible)
{
	this->topSide = false;
	this->bottomSide = false;
	this->leftSide = false;
	this->rightSide = false;

	this->sandBlockFalls = false;

	this->destructible = destructible;

	this->fallCounter = 0;
}

void SandBlock::initTexture()
{
	if (!this->texture.loadFromFile("resources/textures/sand_block.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block.png" << std::endl;
	}

	if (!this->textureTopLeft.loadFromFile("resources/textures/sand_block_top_left.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_top_left.png" << std::endl;
	}

	if (!this->textureLeft.loadFromFile("resources/textures/sand_block_left.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_left.png" << std::endl;
	}

	if (!this->textureBottomLeft.loadFromFile("resources/textures/sand_block_bottom_left.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_bottom_left.png" << std::endl;
	}

	if (!this->textureBottom.loadFromFile("resources/textures/sand_block_bottom.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_bottom.png" << std::endl;
	}

	if (!this->textureBottomRight.loadFromFile("resources/textures/sand_block_bottom_right.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_bottom_right.png" << std::endl;
	}

	if (!this->textureRight.loadFromFile("resources/textures/sand_block_right.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_right.png" << std::endl;
	}

	if (!this->textureTopRight.loadFromFile("resources/textures/sand_block_top_right.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_top_right.png" << std::endl;
	}

	if (!this->textureTop.loadFromFile("resources/textures/sand_block_top.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_top.png" << std::endl;
	}

	if (!this->textureTopBottom.loadFromFile("resources/textures/sand_block_top_bottom.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_top_bottom.png" << std::endl;
	}

	if (!this->textureLeftRight.loadFromFile("resources/textures/sand_block_left_right.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_left_right.png" << std::endl;
	}

	if (!this->textureTopBottomLeft.loadFromFile("resources/textures/sand_block_top_bottom_left.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_top_bottom_left.png" << std::endl;
	}

	if (!this->textureTopBottomRight.loadFromFile("resources/textures/sand_block_top_bottom_right.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_top_bottom_right.png" << std::endl;
	}

	if (!this->textureTopLeftRight.loadFromFile("resources/textures/sand_block_top_left_right.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_top_left_right.png" << std::endl;
	}

	if (!this->textureBottomLeftRight.loadFromFile("resources/textures/sand_block_bottom_left_right.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_bottom_left_right.png" << std::endl;
	}

	if (!this->textureTopBottomLeftRight.loadFromFile("resources/textures/sand_block_top_bottom_left_right.png"))
	{
		std::cerr << "ERROR > SandBlock::initTexture::Could not load texture file: " << "resources/textures/sand_block_top_bottom_left_right.png" << std::endl;
	}
}

void SandBlock::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));

	if (!this->isDestructible())
	{
		this->sprite.setColor(sf::Color(255, 192, 203));
	}
}

void SandBlock::initPosition(sf::Vector2f position)
{
	this->sprite.setOrigin(this->getTextureCenterCoordinates(this->sprite));
	this->sprite.setPosition(position + this->getTextureCenterCoordinates(this->sprite));
}

SandBlock::SandBlock(bool destructible, sf::Vector2f position)
{
	this->initVariables(destructible);
	this->initTexture();
	this->initSprite();
	this->initPosition(position);
}

SandBlock::~SandBlock()
{

}

sf::Vector2f SandBlock::getTextureCenterCoordinates(sf::Sprite sprite)
{
	return sf::Vector2f(sprite.getTexture()->getSize().x * 0.5f, sprite.getTexture()->getSize().y * 0.5f);
}

sf::Sprite SandBlock::getSprite()
{
	return this->sprite;
}

sf::Vector2f SandBlock::getPosition()
{
	return this->sprite.getPosition();
}

bool SandBlock::isDestructible()
{
	return this->destructible;
}

void SandBlock::moveSprite(sf::Vector2f position)
{
	this->sprite.move(position);
}

void SandBlock::sandBlockFall()
{
	this->moveSprite(sf::Vector2f(0.f, 4.f));
}

bool SandBlock::getFallValue()
{
	return this->sandBlockFalls;
}

void SandBlock::setFallValue(bool value)
{
	this->sandBlockFalls = value;
}

bool SandBlock::getTopSide()
{
	return this->topSide;
}

bool SandBlock::getBottomSide()
{
	return this->bottomSide;
}

bool SandBlock::getLeftSide()
{
	return this->leftSide;
}

bool SandBlock::getRightSide()
{
	return this->rightSide;
}

void SandBlock::setSides(bool top, bool bottom, bool left, bool right)
{
	this->topSide = top;
	this->bottomSide = bottom;
	this->leftSide = left;
	this->rightSide = right;
}

void SandBlock::updateTexture(bool top, bool bottom, bool left, bool right)
{
	if (!top && !bottom && !left && !right)
	{
		this->sprite.setTexture(this->texture);
	}
	else if (top && !bottom && left && !right)
	{
		this->sprite.setTexture(this->textureTopLeft);
	}
	else if (!top && !bottom && left && !right)
	{
		this->sprite.setTexture(this->textureLeft);
	}
	else if (!top && bottom && left && !right)
	{
		this->sprite.setTexture(this->textureBottomLeft);
	}
	else if (!top && bottom && !left && !right)
	{
		this->sprite.setTexture(this->textureBottom);
	}
	else if (!top && bottom && !left && right)
	{
		this->sprite.setTexture(this->textureBottomRight);
	}
	else if (!top && !bottom && !left && right)
	{
		this->sprite.setTexture(this->textureRight);
	}
	else if (top && !bottom && !left && right)
	{
		this->sprite.setTexture(this->textureTopRight);
	}
	else if (top && !bottom && !left && !right)
	{
		this->sprite.setTexture(this->textureTop);
	}
	else if (top && bottom && !left && !right)
	{
		this->sprite.setTexture(this->textureTopBottom);
	}
	else if (!top && !bottom && left && right)
	{
		this->sprite.setTexture(this->textureLeftRight);
	}
	else if (top && bottom && left && !right)
	{
		this->sprite.setTexture(this->textureTopBottomLeft);
	}
	else if (top && bottom && !left && right)
	{
		this->sprite.setTexture(this->textureTopBottomRight);
	}
	else if (top && !bottom && left && right)
	{
		this->sprite.setTexture(this->textureTopLeftRight);
	}
	else if (!top && bottom && left && right)
	{
		this->sprite.setTexture(this->textureBottomLeftRight);
	}
	else if (top && bottom && left && right)
	{
		this->sprite.setTexture(this->textureTopBottomLeftRight);
	}

	this->sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}

void SandBlock::update()
{
	this->updateTexture(this->getTopSide(), this->getBottomSide(), this->getLeftSide(), this->getRightSide());

	if (this->sandBlockFalls)
	{
		this->sandBlockFall();

		this->fallCounter++;
		if (this->fallCounter >= 10)
		{
			this->fallCounter = 0;
			this->sandBlockFalls = false;
		}
	}
}

void SandBlock::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
