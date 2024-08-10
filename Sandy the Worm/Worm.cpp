#include "Worm.h"

void Worm::initVariables()
{
	this->wormFalls = false;

	this->fallCounter = 0;

	this->wormPositions = { 
		this->head->getPosition(),
		this->bodyFirst->getPosition(),
		this->bodySecond->getPosition(),
		this->tail->getPosition() 
	};
}

Worm::Worm(sf::Vector2f spawnPosition)
{
	this->head = new WormHead(spawnPosition);
	this->bodyFirst = new WormBody(sf::Vector2f(spawnPosition.x + 40.f, spawnPosition.y), sf::Vector2f(spawnPosition.x + 20.f, spawnPosition.y + 20.f));
	this->bodySecond = new WormBody(sf::Vector2f(spawnPosition.x + 80.f, spawnPosition.y), sf::Vector2f(spawnPosition.x + 60.f, spawnPosition.y + 20.f));
	this->tail = new WormTail(sf::Vector2f(spawnPosition.x + 120.f, spawnPosition.y), sf::Vector2f(spawnPosition.x + 100.f, spawnPosition.y + 20.f));
	this->initVariables();
}

Worm::~Worm()
{

}

void Worm::resetWormPositions()
{
	this->wormPositions = {
		this->head->getPosition(),
		this->bodyFirst->getPosition(),
		this->bodySecond->getPosition(),
		this->tail->getPosition()
	};
}

void Worm::moveWorm()
{
	this->bodyFirst->setFollowPosition();
	this->bodyFirst->resetFollowPosition(this->head->getPosition());
	this->bodySecond->setFollowPosition();
	this->bodySecond->resetFollowPosition(this->bodyFirst->getPosition());
	this->tail->setFollowPosition();
	this->tail->resetFollowPosition(this->bodySecond->getPosition());
}

bool Worm::wormCanMove(std::vector<SandBlock*> blocks, sf::Vector2f futurePosition)
{
	bool canMove = true;
	this->resetWormPositions();

	for (SandBlock* block : blocks)
	{
		if (futurePosition == this->bodyFirst->getPosition() || futurePosition.y > 480.f || (futurePosition == block->getPosition() && !block->isDestructible()))
		{
			canMove = false;
		}
	}

	/*...
	std::cout << "futX " << futurePosition.x << " " << this->bodyFirst->getPosition().x << " " << this->bodySecond->getPosition().x << " " << this->tail->getPosition().x << "\n";
	std::cout << "futY " << futurePosition.y << " " << this->bodyFirst->getPosition().y << " " << this->bodySecond->getPosition().y << " " << this->tail->getPosition().y << "\n\n";
	...*/
	/*...*/
	std::cout << "X " << wormPositions[0].x << " " << wormPositions[1].x << " " << wormPositions[2].x << " " << wormPositions[3].x << "\n";
	std::cout << "Y " << wormPositions[0].y << " " << wormPositions[1].y << " " << wormPositions[2].y << " " << wormPositions[3].y << "\n";
	/*...*/


	//4Y vertical
	/*unsigned i = 0;
	for (sf::Vector2f pos : this->wormPositions)
	{
		if (futurePosition.x == pos.x) i++;

		if (i == 4) {
			if (futurePosition.y < this->wormPositions[3].y) canMove = false;
		}
	}*/

	return canMove;
}

bool Worm::getFallValue()
{
	return this->wormFalls;
}

void Worm::setFallValue(bool value)
{
	this->wormFalls = value;
}

void Worm::wormFall()
{
	this->head->moveSprite(sf::Vector2f(0.f, 4.f));

	this->bodyFirst->moveSprite(sf::Vector2f(0.f, 4.f));

	this->bodySecond->moveSprite(sf::Vector2f(0.f, 4.f));

	this->tail->moveSprite(sf::Vector2f(0.f, 4.f));

	this->bodyFirst->resetFollowPosition(this->head->getPosition());
	this->bodySecond->resetFollowPosition(this->bodyFirst->getPosition());
	this->tail->resetFollowPosition(this->bodySecond->getPosition());
}

WormHead* Worm::getWormHead()
{
	return this->head;
}


WormBody* Worm::getWormBodyFirst()
{
	return this->bodyFirst;
}

WormBody* Worm::getWormBodySecond()
{
	return this->bodySecond;
}

WormTail* Worm::getWormTail()
{
	return this->tail;
}

void Worm::updateWorm()
{
	this->head->update();
	this->bodyFirst->update();
	this->bodySecond->update();
	this->tail->update();

	if (this->wormFalls)
	{
		this->wormFall();

		this->fallCounter++;
		if (this->fallCounter >= 10)
		{
			this->fallCounter = 0;
			this->wormFalls = false;
		}
	}
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
