#pragma once

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

	bool keyHeldA;
	bool keyHeldD;
	bool keyHeldW;
	bool keyHeldS;

	void initVariables();

public:
	Worm (float x, float y);
	virtual ~Worm();

	//Accessors


	//Functions
	void moveWorm();

	void updateInput();
	void updateWorm();
	template<class T, class N, class K> void updateBodySides(T firstPartWorm, N secondPartWorm, K thridPartWorm);
	void updateTailSides(WormTail& partWorm);
	void update();
	void render(sf::RenderTarget& target);
};
