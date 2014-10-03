#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Dame.h"
#include "Missile.h"
#include "Asteroide.h"

class MyGraphicEngine :public GraphicEngine {







	char * str;
public:
	std::vector<Dame * > *dames = new std::vector < Dame * >;
	std::vector<Missile * > *missiles = new std::vector < Missile * >;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;

	int col;
	MyGraphicEngine();

	MyGraphicEngine(std::vector<Dame *> * dames_, std::vector<Asteroide * > * asteroides_) :
		dames(dames_),
		asteroides(asteroides_)
	{}
	~MyGraphicEngine();

	float x, y, w, h, r, g, b;
	virtual void Draw();
	void color();
	virtual void reshape(int width, int height);


};


