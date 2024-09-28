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
	TextureManager::getInstance().loadTexture("sand_block", "resources/textures/sand_block.png");
	TextureManager::getInstance().loadTexture("sand_block_top_left", "resources/textures/sand_block_top_left.png");
	TextureManager::getInstance().loadTexture("sand_block_left", "resources/textures/sand_block_left.png");
	TextureManager::getInstance().loadTexture("sand_block_bottom_left", "resources/textures/sand_block_bottom_left.png");
	TextureManager::getInstance().loadTexture("sand_block_bottom", "resources/textures/sand_block_bottom.png");
	TextureManager::getInstance().loadTexture("sand_block_bottom_right", "resources/textures/sand_block_bottom_right.png");
	TextureManager::getInstance().loadTexture("sand_block_right", "resources/textures/sand_block_right.png");
	TextureManager::getInstance().loadTexture("sand_block_top_right", "resources/textures/sand_block_top_right.png");
	TextureManager::getInstance().loadTexture("sand_block_top", "resources/textures/sand_block_top.png");
	TextureManager::getInstance().loadTexture("sand_block_top_bottom", "resources/textures/sand_block_top_bottom.png");
	TextureManager::getInstance().loadTexture("sand_block_left_right", "resources/textures/sand_block_left_right.png");
	TextureManager::getInstance().loadTexture("sand_block_top_bottom_left", "resources/textures/sand_block_top_bottom_left.png");
	TextureManager::getInstance().loadTexture("sand_block_top_bottom_right", "resources/textures/sand_block_top_bottom_right.png");
	TextureManager::getInstance().loadTexture("sand_block_top_left_right", "resources/textures/sand_block_top_left_right.png");
	TextureManager::getInstance().loadTexture("sand_block_bottom_left_right", "resources/textures/sand_block_bottom_left_right.png");
	TextureManager::getInstance().loadTexture("sand_block_top_bottom_left_right", "resources/textures/sand_block_top_bottom_left_right.png");
}

void SandBlock::initSprite()
{
	this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block"));
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
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block"));
	}
	else if (top && !bottom && left && !right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_top_left"));
	}
	else if (!top && !bottom && left && !right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_left"));
	}
	else if (!top && bottom && left && !right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_bottom_left"));
	}
	else if (!top && bottom && !left && !right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_bottom"));
	}
	else if (!top && bottom && !left && right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_bottom_right"));
	}
	else if (!top && !bottom && !left && right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_right"));
	}
	else if (top && !bottom && !left && right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_top_right"));
	}
	else if (top && !bottom && !left && !right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_top"));
	}
	else if (top && bottom && !left && !right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_top_bottom"));
	}
	else if (!top && !bottom && left && right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_left_right"));
	}
	else if (top && bottom && left && !right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_top_bottom_left"));
	}
	else if (top && bottom && !left && right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_top_bottom_right"));
	}
	else if (top && !bottom && left && right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_top_left_right"));
	}
	else if (!top && bottom && left && right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_bottom_left_right"));
	}
	else if (top && bottom && left && right)
	{
		this->sprite.setTexture(TextureManager::getInstance().getTexture("sand_block_top_bottom_left_right"));
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
