#include "Menu.h"

void Menu::initVariables()
{
	this->welcomeScreenActive = true;

	this->gameStarted = false;

	this->allIconLevels = { &this->spriteIconlvl1, &this->spriteIconlvl2, &this->spriteIconlvl3, &this->spriteIconlvl4, &this->spriteIconlvl5, &this->spriteIconlvl6 };

	this->shownIconLevels = { { 4, &this->spriteIconlvl5 }, { 5, &this->spriteIconlvl6 }, { 0, &this->spriteIconlvl1 }, { 1, &this->spriteIconlvl2 }, { 2, &this->spriteIconlvl3 } };
}

void Menu::initTexture()
{
	if (!this->textureWelcomeScreen.loadFromFile("Textures/welcome_screen.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureWelcomeTitle.loadFromFile("Textures/welcome_title.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureButtonPlay.loadFromFile("Textures/button_play.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureButtonSwitch.loadFromFile("Textures/button_switch.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureSelectedlvlFrame.loadFromFile("Textures/selected_lvl_frame.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureIconlvl1.loadFromFile("Textures/icon_lvl1.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureIconlvl2.loadFromFile("Textures/icon_lvl2.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureIconlvl3.loadFromFile("Textures/icon_lvl3.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureIconlvl4.loadFromFile("Textures/icon_lvl4.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureIconlvl5.loadFromFile("Textures/icon_lvl5.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}

	if (!this->textureIconlvl6.loadFromFile("Textures/icon_lvl6.png"))
	{
		std::cout << "ERROR > Menu::initTexture::Could not load texture file." << "\n";
	}
}

void Menu::initSprite()
{
	this->spriteWelcomeScreen.setTexture(this->textureWelcomeScreen);
	this->spriteWelcomeScreen.setTextureRect(sf::IntRect(0, 0, 800, 600));

	this->spriteWelcomeTitle.setTexture(this->textureWelcomeTitle);
	this->spriteWelcomeTitle.setTextureRect(sf::IntRect(0, 0, 800, 600));

	this->spriteButtonPlay.setTexture(this->textureButtonPlay);
	this->spriteButtonPlay.setTextureRect(sf::IntRect(0, 0, 300, 100));

	this->spriteFirstButtonSwitch.setTexture(this->textureButtonSwitch);
	this->spriteFirstButtonSwitch.setTextureRect(sf::IntRect(0, 0, 25, 40));

	this->spriteSecondButtonSwitch.setTexture(this->textureButtonSwitch);
	this->spriteSecondButtonSwitch.setTextureRect(sf::IntRect(0, 0, 25, 40));
	this->spriteSecondButtonSwitch.setScale(sf::Vector2f(-1.f, 1.f));

	this->spriteSelectedlvlFrame.setTexture(this->textureSelectedlvlFrame);
	this->spriteSelectedlvlFrame.setTextureRect(sf::IntRect(0, 0, 84, 84));

	this->spriteIconlvl1.setTexture(this->textureIconlvl1);
	this->spriteIconlvl1.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl2.setTexture(this->textureIconlvl2);
	this->spriteIconlvl2.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl3.setTexture(this->textureIconlvl3);
	this->spriteIconlvl3.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl4.setTexture(this->textureIconlvl4);
	this->spriteIconlvl4.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl5.setTexture(this->textureIconlvl5);
	this->spriteIconlvl5.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl6.setTexture(this->textureIconlvl6);
	this->spriteIconlvl6.setTextureRect(sf::IntRect(0, 0, 76, 76));
}

void Menu::initPosition()
{
	this->spriteWelcomeScreen.setOrigin(this->getTextureCenterCoordinates(this->spriteWelcomeScreen));
	this->spriteWelcomeScreen.setPosition(sf::Vector2f(0.f, 0.f) + this->getTextureCenterCoordinates(this->spriteWelcomeScreen));

	this->spriteWelcomeTitle.setOrigin(this->getTextureCenterCoordinates(this->spriteWelcomeTitle));
	this->spriteWelcomeTitle.setPosition(sf::Vector2f(0.f, 0.f) + this->getTextureCenterCoordinates(this->spriteWelcomeTitle));

	this->spriteButtonPlay.setOrigin(this->getTextureCenterCoordinates(this->spriteButtonPlay));
	this->spriteButtonPlay.setPosition(sf::Vector2f(250.f, 325.f) + this->getTextureCenterCoordinates(this->spriteButtonPlay));

	this->spriteFirstButtonSwitch.setOrigin(this->getTextureCenterCoordinates(this->spriteFirstButtonSwitch));
	this->spriteFirstButtonSwitch.setPosition(sf::Vector2f(654.f, 193.f) + this->getTextureCenterCoordinates(this->spriteFirstButtonSwitch));

	this->spriteSecondButtonSwitch.setOrigin(this->getTextureCenterCoordinates(this->spriteSecondButtonSwitch));
	this->spriteSecondButtonSwitch.setPosition(sf::Vector2f(121.f, 193.f) + this->getTextureCenterCoordinates(this->spriteSecondButtonSwitch));

	this->spriteSelectedlvlFrame.setOrigin(this->getTextureCenterCoordinates(this->spriteSelectedlvlFrame));
	this->spriteSelectedlvlFrame.setPosition(sf::Vector2f(358.f, 171.f) + this->getTextureCenterCoordinates(this->spriteSelectedlvlFrame));

	this->spriteIconlvl1.setOrigin(this->getTextureCenterCoordinates(this->spriteIconlvl1));
	this->spriteIconlvl1.setPosition(sf::Vector2f(362.f, 175.f) + this->getTextureCenterCoordinates(this->spriteIconlvl1));

	this->spriteIconlvl2.setOrigin(this->getTextureCenterCoordinates(this->spriteIconlvl2));
	this->spriteIconlvl2.setPosition(sf::Vector2f(460.f, 175.f) + this->getTextureCenterCoordinates(this->spriteIconlvl2));

	this->spriteIconlvl3.setOrigin(this->getTextureCenterCoordinates(this->spriteIconlvl3));
	this->spriteIconlvl3.setPosition(sf::Vector2f(558.f, 175.f) + this->getTextureCenterCoordinates(this->spriteIconlvl3));

	this->spriteIconlvl4.setOrigin(this->getTextureCenterCoordinates(this->spriteIconlvl4));
	//this->spriteIconlvl4.setPosition(sf::Vector2f(166.f, 175.f) + this->getTextureCenterCoordinates(this->spriteIconlvl4));

	this->spriteIconlvl5.setOrigin(this->getTextureCenterCoordinates(this->spriteIconlvl5));
	this->spriteIconlvl5.setPosition(sf::Vector2f(166.f, 175.f) + this->getTextureCenterCoordinates(this->spriteIconlvl5));

	this->spriteIconlvl6.setOrigin(this->getTextureCenterCoordinates(this->spriteIconlvl6));
	this->spriteIconlvl6.setPosition(sf::Vector2f(264.f, 175.f) + this->getTextureCenterCoordinates(this->spriteIconlvl6));
}

Menu::Menu()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initPosition();
}

Menu::~Menu()
{

}

sf::Vector2f Menu::getTextureCenterCoordinates(sf::Sprite sprite)
{
	return sf::Vector2f(sprite.getTexture()->getSize().x * 0.5f, sprite.getTexture()->getSize().y * 0.5f);
}

sf::Sprite& Menu::getSpriteButtonPlay()
{
	return this->spriteButtonPlay;
}

sf::Sprite& Menu::getSpriteFirstButtonSwitch()
{
	return this->spriteFirstButtonSwitch;
}

sf::Sprite& Menu::getSpriteSecondButtonSwitch()
{
	return this->spriteSecondButtonSwitch;
}

bool Menu::getWelcomeScreenActive()
{
	return this->welcomeScreenActive;
}

void Menu::setWelcomeScreenActive(bool value)
{
	this->welcomeScreenActive = value;
}

bool Menu::getGameStarted()
{
	return this->gameStarted;
}

void Menu::setGameStarted(bool value)
{
	this->gameStarted = value;
}

std::vector<sf::Sprite*>& Menu::getAllIconLevels()
{
	return this->allIconLevels;
}

std::vector<std::pair<int, sf::Sprite*>>& Menu::getShownIconLevels()
{
	return this->shownIconLevels;
}

void Menu::updateWelcomeScreen()
{
	
}

void Menu::update()
{
	if (this->getWelcomeScreenActive())
	{
		this->updateWelcomeScreen();
	}
	else
	{
		if (this->getGameStarted())
		{
			this->setGameStarted(false);
		}
	}
}

void Menu::render(sf::RenderTarget& target)
{
	target.draw(this->spriteWelcomeScreen);

	if (this->getWelcomeScreenActive())
	{
		target.draw(this->spriteWelcomeTitle);
	}
	else
	{
		target.draw(this->spriteButtonPlay);
		target.draw(this->spriteFirstButtonSwitch);
		target.draw(this->spriteSecondButtonSwitch);

		for (auto icon : this->shownIconLevels)
		{
			//std::cout << icon.first << " zzzzzzzz \n";
			target.draw(*icon.second);
		}

		target.draw(this->spriteSelectedlvlFrame);
	}
}
