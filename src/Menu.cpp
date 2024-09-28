#include "Menu.h"

void Menu::initVariables()
{
	this->welcomeScreenActive = true;

	this->allIconLevels = { &this->spriteIconlvl1, &this->spriteIconlvl2, &this->spriteIconlvl3, &this->spriteIconlvl4, &this->spriteIconlvl5, &this->spriteIconlvl6 };

	this->shownIconLevels = { { 4, &this->spriteIconlvl5 }, { 5, &this->spriteIconlvl6 }, { 0, &this->spriteIconlvl1 }, { 1, &this->spriteIconlvl2 }, { 2, &this->spriteIconlvl3 } };
}

void Menu::initFonts()
{
	if (!this->font.loadFromFile("resources/fonts/PressStart2P-Regular.ttf"))
	{
		std::cerr << "ERROR > Menu::initFonts::Failed to load font: " << "resources/fonts/PressStart2P-Regular.ttf" << std::endl;
	}
}

void Menu::initText()
{
	this->welcomeScreenText.setFont(this->font);
	this->welcomeScreenText.setCharacterSize(24);
	this->welcomeScreenText.setFillColor(sf::Color(211, 27, 89));
	this->welcomeScreenText.setString("Press SPACE to continue");
	this->welcomeScreenText.setPosition(sf::Vector2f((float) (800 - this->welcomeScreenText.getGlobalBounds().width) / 2, 550.f));
}

void Menu::initTexture()
{
	TextureManager::getInstance().loadTexture("welcome_screen", "resources/textures/welcome_screen.png");
	TextureManager::getInstance().loadTexture("welcome_title", "resources/textures/welcome_title.png");
	TextureManager::getInstance().loadTexture("button_play", "resources/textures/button_play.png");
	TextureManager::getInstance().loadTexture("button_switch", "resources/textures/button_switch.png");
	TextureManager::getInstance().loadTexture("selected_lvl_frame", "resources/textures/selected_lvl_frame.png");
	TextureManager::getInstance().loadTexture("icon_lvl1", "resources/textures/icon_lvl1.png");
	TextureManager::getInstance().loadTexture("icon_lvl2", "resources/textures/icon_lvl2.png");
	TextureManager::getInstance().loadTexture("icon_lvl3", "resources/textures/icon_lvl3.png");
	TextureManager::getInstance().loadTexture("icon_lvl4", "resources/textures/icon_lvl4.png");
	TextureManager::getInstance().loadTexture("icon_lvl5", "resources/textures/icon_lvl5.png");
	TextureManager::getInstance().loadTexture("icon_lvl6", "resources/textures/icon_lvl6.png");
}

void Menu::initSprite()
{
	this->spriteWelcomeScreen.setTexture(TextureManager::getInstance().getTexture("welcome_screen"));
	this->spriteWelcomeScreen.setTextureRect(sf::IntRect(0, 0, 800, 600));

	this->spriteWelcomeTitle.setTexture(TextureManager::getInstance().getTexture("welcome_title"));
	this->spriteWelcomeTitle.setTextureRect(sf::IntRect(0, 0, 800, 600));

	this->spriteButtonPlay.setTexture(TextureManager::getInstance().getTexture("button_play"));
	this->spriteButtonPlay.setTextureRect(sf::IntRect(0, 0, 300, 100));

	this->spriteFirstButtonSwitch.setTexture(TextureManager::getInstance().getTexture("button_switch"));
	this->spriteFirstButtonSwitch.setTextureRect(sf::IntRect(0, 0, 25, 40));

	this->spriteSecondButtonSwitch.setTexture(TextureManager::getInstance().getTexture("button_switch"));
	this->spriteSecondButtonSwitch.setTextureRect(sf::IntRect(0, 0, 25, 40));
	this->spriteSecondButtonSwitch.setScale(sf::Vector2f(-1.f, 1.f));

	this->spriteSelectedlvlFrame.setTexture(TextureManager::getInstance().getTexture("selected_lvl_frame"));
	this->spriteSelectedlvlFrame.setTextureRect(sf::IntRect(0, 0, 84, 84));

	this->spriteIconlvl1.setTexture(TextureManager::getInstance().getTexture("icon_lvl1"));
	this->spriteIconlvl1.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl2.setTexture(TextureManager::getInstance().getTexture("icon_lvl2"));
	this->spriteIconlvl2.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl3.setTexture(TextureManager::getInstance().getTexture("icon_lvl3"));
	this->spriteIconlvl3.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl4.setTexture(TextureManager::getInstance().getTexture("icon_lvl4"));
	this->spriteIconlvl4.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl5.setTexture(TextureManager::getInstance().getTexture("icon_lvl5"));
	this->spriteIconlvl5.setTextureRect(sf::IntRect(0, 0, 76, 76));

	this->spriteIconlvl6.setTexture(TextureManager::getInstance().getTexture("icon_lvl6"));
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
	this->initFonts();
	this->initText();
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
}

void Menu::renderText(sf::RenderTarget& target)
{
	
}

void Menu::render(sf::RenderTarget& target)
{
	target.draw(this->spriteWelcomeScreen);

	if (this->getWelcomeScreenActive())
	{
		target.draw(this->spriteWelcomeTitle);
		target.draw(this->welcomeScreenText);
	}
	else
	{
		target.draw(this->spriteButtonPlay);
		target.draw(this->spriteFirstButtonSwitch);
		target.draw(this->spriteSecondButtonSwitch);

		for (auto icon : this->shownIconLevels)
		{
			target.draw(*icon.second);
		}

		target.draw(this->spriteSelectedlvlFrame);
	}
}
