#pragma once
#include "Missile.h"
#include "Asteroide.h"

class Collision{

public:
	bool isItTheSameBox(Asteroide *ast, Missile *miss);
	bool isItTheSameBox(Asteroide *ast, Vaisseau *vais);
};