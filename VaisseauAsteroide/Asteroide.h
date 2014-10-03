#pragma once
#include "GraphicPrimitives.h"



class Asteroide {

public:
	bool isdestruct;
	Asteroide();

	Asteroide(float posX_ = 0.0f, float posY_ = 0.0f) :
		posX(posX_), posY(posY_), VposX(0.01f), VposY(0.02f)
	{}

	~Asteroide();


	float posX, posY;
	float VposX, VposY;

	void draw();
	void tick();
	void drawAsteroide();

};