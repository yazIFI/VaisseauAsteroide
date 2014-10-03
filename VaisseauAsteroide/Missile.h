#pragma once
#include "GraphicPrimitives.h"
#include "Dame.h"

class Missile {

public:

	Missile();

	Missile(float posX_ = 0.0f, float posY_ = 0.0f) :
		posX(posX_), posY(posY_), width(0.1f), height(0.1f), VposX(0.01f){}

	~Missile();


	float posX, posY, width, height;
	float VposX;

	void drawAsteroide();
	void tick();

};