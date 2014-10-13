#pragma once
#include "GraphicPrimitives.h"

 class Missile{

public:
	Missile();
	Missile(float posX_ = 0.0f, float posY_ = 0.0f) :
		posX(posX_),
		posY(posY_),
		width(0.02),
		height(0.01)
	{}

	~Missile();


	float posX, posY, width, height;
	float VposX;
	void drawMissile();
	void tick();

};