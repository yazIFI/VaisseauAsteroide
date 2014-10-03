#pragma once

#include "Engine.h"
#include "Missile.h"
#include "Dame.h"
#include "Asteroide.h"


class MyGameEngine :public GameEngine {

public:
	int compte = 0;
	std::vector<Dame * > *dames = new std::vector < Dame * >;
	std::vector<Missile * > *missiles = new std::vector < Missile * >;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;

	MyGameEngine();

	MyGameEngine(std::vector<Dame *> *dames_, std::vector<Asteroide * > * asteroides_) :
		dames(dames_),
		asteroides(asteroides_)

	{

	}
	~MyGameEngine();
	virtual void idle();

};
