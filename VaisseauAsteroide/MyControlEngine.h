#pragma once
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "Dame.h"
#include "Missile.h"
#include "Asteroide.h"

class MyControlEngine :public ControlEngine {
	std::vector<Dame * > *dames;
	std::vector<Missile * > *missiles;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;

public:
	MyControlEngine();
	MyControlEngine(std::vector<Dame * > * dames_) :dames(dames_){}
	MyControlEngine(std::vector<Missile * > * missiles_) :missiles(missiles_){}
	MyControlEngine(std::vector<Asteroide * > * asteroides_) :asteroides(asteroides_){}
	~MyControlEngine();

	virtual void MouseCallback(int button, int state, int x, int y);

	void color();
	int change(float x, float y);
	int incr;
};
