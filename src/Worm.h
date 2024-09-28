#pragma once

#include "SandBlock.h"
#include "WormHead.h"
#include "WormBody.h"
#include "WormTail.h"

class Worm
{
private:
	WormHead* head;
	WormBody* bodyFirst;
	WormBody* bodySecond;
	WormTail* tail;

	bool wormFalls;

	unsigned fallCounter;

	std::vector<sf::Vector2f> wormPositions;

	void initVariables();

public:
	Worm (sf::Vector2f spawnPosition);
	virtual ~Worm();

	//Accessors
	void resetWormPositions();
	void moveWorm();

	//Functions
	bool wormCanMove(std::vector<SandBlock*> blocks, sf::Vector2f futurePosition);
	bool getFallValue();
	void setFallValue(bool value);
	void wormFall();
	WormHead* getWormHead();
	WormBody* getWormBodyFirst();
	WormBody* getWormBodySecond();
	WormTail* getWormTail();

	void updateWorm();
	template<class T, class N, class K> void updateBodySides(T firstPartWorm, N secondPartWorm, K thridPartWorm);
	void updateTailSides(WormTail& partWorm);
	void update();
	void render(sf::RenderTarget& target);
};
