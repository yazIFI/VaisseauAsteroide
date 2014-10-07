#pragma once
#include "GraphicPrimitives.h"
#include "Missile.h"


class Asteroide {

public:
	//bool isdestruct;
	Asteroide();

	Asteroide(float posX_ = 0.0f, float posY_ = 0.0f) :
		posX(posX_), posY(posY_), VposX(0.005f), VposY(0.02f),
		r(1.0f), g(0.6f), b(0.5f)
	{}

	~Asteroide();


	float posX, posY;
	float VposX, VposY;
	float r, g, b;

	void draw();
	void tick();
	void drawAsteroide();
	bool isCollided(float mposX, float aposX, float aposY,float mposY);
	bool heFreed(float x);

};