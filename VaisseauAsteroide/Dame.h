#pragma once
#include "GraphicPrimitives.h"

class Dame {

public:

	Dame();

	Dame(float posX_ = 0.0f, float posY_ = 0.0f, float r_ = 0.0f, float g_ = 0.0f, float b_ = 0.0f) :
		posX(posX_), posY(posY_), posX2(posX_), width(0.1f), height(0.1f), VposX(0.01f), VposY(0.02f), Vwidth(0.01f), Vheight(-0.02f),
		r(r_), g(g_), b(b_){}

	~Dame();


	float posX, posY, posX2, width, height, r, g, b;
	float VposX, VposY, Vwidth, Vheight;

	void draw();
	void tick();
	void drawVaisseau();
	void drawMissile();

};