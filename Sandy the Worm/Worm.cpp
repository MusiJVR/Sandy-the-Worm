#include "Worm.h"

void Worm::initVariables()
{
	this->keyHeldA = false;
	this->keyHeldD = false;
	this->keyHeldW = false;
	this->keyHeldS = false;
}

Worm::Worm(float x, float y)
{
	this->initVariables();
	this->head = new WormHead(sf::Vector2f(320.f, 440.f));
	this->bodyFirst = new WormBody(sf::Vector2f(360.f, 440.f), sf::Vector2f(340.f, 460.f));
	this->bodySecond = new WormBody(sf::Vector2f(400.f, 440.f), sf::Vector2f(380.f, 460.f));
	this->tail = new WormTail(sf::Vector2f(440.f, 440.f), sf::Vector2f(420.f, 460.f));
}

Worm::~Worm()
{

}

void Worm::moveWorm()
{
	this->bodyFirst->moveSprite();
	this->bodyFirst->setFollowPosition(this->head->getPosition());
	this->bodySecond->moveSprite();
	this->bodySecond->setFollowPosition(this->bodyFirst->getPosition());
	this->tail->moveSprite();
	this->tail->setFollowPosition(this->bodySecond->getPosition());
}

void Worm::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!keyHeldA)
		{
			this->keyHeldA = true;
			this->head->moveSprite(sf::Vector2f(- 40.f, 0.f));
			this->head->setSides(true, true, true, false);
			this->moveWorm();
			
			std::cout << "A" << "\n";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!keyHeldD)
		{
			this->keyHeldD = true;
			this->head->moveSprite(sf::Vector2f(40.f, 0.f));
			this->head->setSides(true, true, false, true);
			this->moveWorm();

			std::cout << "D" << "\n";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!keyHeldW)
		{
			this->keyHeldW = true;
			this->head->moveSprite(sf::Vector2f(0.f, -40.f));
			this->head->setSides(true, false, true, true);
			this->moveWorm();

			std::cout << "W" << "\n";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (!keyHeldS)
		{
			this->keyHeldS = true;
			this->head->moveSprite(sf::Vector2f(0.f, 40.f));
			this->head->setSides(false, true, true, true);
			this->moveWorm();

			std::cout << "S" << "\n";
		}
	}
	else initVariables();
}

void Worm::updateWorm()
{
	this->head->update();
	this->bodyFirst->update();
	this->bodySecond->update();
	this->tail->update();
}

template<class T, class N, class K> void Worm::updateBodySides(T firstPartWorm, N secondPartWorm, K thridPartWorm)
{
	if ((firstPartWorm->getPosition().y > secondPartWorm->getPosition().y && firstPartWorm->getPosition().y < thridPartWorm->getPosition().y)
		|| (firstPartWorm->getPosition().y > thridPartWorm->getPosition().y && firstPartWorm->getPosition().y < secondPartWorm->getPosition().y))
	{
		firstPartWorm->setSides(false, false, true, true);
	}
	else if ((firstPartWorm->getPosition().x > secondPartWorm->getPosition().x && firstPartWorm->getPosition().x < thridPartWorm->getPosition().x)
		|| (firstPartWorm->getPosition().x > thridPartWorm->getPosition().x && firstPartWorm->getPosition().x < secondPartWorm->getPosition().x))
	{
		firstPartWorm->setSides(true, true, false, false);
	}
	else if ((firstPartWorm->getPosition().x > secondPartWorm->getPosition().x && firstPartWorm->getPosition().y < thridPartWorm->getPosition().y)
		|| (firstPartWorm->getPosition().x > thridPartWorm->getPosition().x && firstPartWorm->getPosition().y < secondPartWorm->getPosition().y))
	{
		firstPartWorm->setSides(true, false, false, true);
	}
	else if ((firstPartWorm->getPosition().x > secondPartWorm->getPosition().x && firstPartWorm->getPosition().y > thridPartWorm->getPosition().y)
		|| (firstPartWorm->getPosition().x > thridPartWorm->getPosition().x && firstPartWorm->getPosition().y > secondPartWorm->getPosition().y))
	{
		firstPartWorm->setSides(false, true, false, true);
	}
	else if ((firstPartWorm->getPosition().y > secondPartWorm->getPosition().y && firstPartWorm->getPosition().x < thridPartWorm->getPosition().x)
		|| (firstPartWorm->getPosition().y > thridPartWorm->getPosition().y && firstPartWorm->getPosition().x < secondPartWorm->getPosition().x))
	{
		firstPartWorm->setSides(false, true, true, false);
	}
	else if ((firstPartWorm->getPosition().y < secondPartWorm->getPosition().y && firstPartWorm->getPosition().x < thridPartWorm->getPosition().x)
		|| (firstPartWorm->getPosition().y < thridPartWorm->getPosition().y && firstPartWorm->getPosition().x < secondPartWorm->getPosition().x))
	{
		firstPartWorm->setSides(true, false, true, false);
	}
}

void Worm::updateTailSides(WormTail& partWorm)
{
	if (partWorm.getPosition().y > this->bodySecond->getPosition().y)
	{
		partWorm.setSides(false, true, true, true);
	}
	else if (partWorm.getPosition().y < this->bodySecond->getPosition().y)
	{
		partWorm.setSides(true, false, true, true);
	}
	else if (partWorm.getPosition().x > this->bodySecond->getPosition().x)
	{
		partWorm.setSides(true, true, false, true);
	}
	else if (partWorm.getPosition().x < this->bodySecond->getPosition().x)
	{
		partWorm.setSides(true, true, true, false);
	}
}

void Worm::update()
{
	this->updateInput();
	this->updateWorm();
	this->updateBodySides(this->bodyFirst, this->head, this->bodySecond);
	this->updateBodySides(this->bodySecond, this->bodyFirst, this->tail);
	this->updateTailSides(*this->tail);
}

void Worm::render(sf::RenderTarget& target)
{
	this->head->render(target);
	this->bodyFirst->render(target);
	this->bodySecond->render(target);
	this->tail->render(target);
}
