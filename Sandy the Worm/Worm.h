#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>

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

	bool keyHeldA, keyHeldD, keyHeldW, keyHeldS, wormFalls;

	unsigned fallCounter;

	std::vector<sf::Vector2f> wormPositions;

	void initVariables();

public:
	Worm (sf::Vector2f spawnPosition);
	virtual ~Worm();

	//Accessors
	void resetKeys();
	void resetWormPositions();

	//Functions
	bool wormCanMove(sf::Vector2f futurePosition);
	void moveWorm();
	bool getFallValue();
	void setFallValue(bool value);
	void wormFall();
	WormHead* getWormHead();
	WormBody* getWormBodyFirst();
	WormBody* getWormBodySecond();
	WormTail* getWormTail();

	void updateInput();
	void updateWorm();
	template<class T, class N, class K> void updateBodySides(T firstPartWorm, N secondPartWorm, K thridPartWorm);
	void updateTailSides(WormTail& partWorm);
	void update();
	void render(sf::RenderTarget& target);
};
