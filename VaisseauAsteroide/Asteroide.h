#pragma once
#include "GraphicPrimitives.h"
#include "Missile.h"
#include "Vaisseau.h"
#include "ListAsteroides.h"

class Asteroide :public ListAsteroides{

public:
	Asteroide();

	Asteroide(float posX_ = 0.0f, float posY_ = 0.0f) :
		posX(posX_), posY(posY_), VposX(0.05f), VposY(0.02f),
		r(.0f), g(0.0f), b(1.0f)
	{}

	~Asteroide();


	float posX, posY;
	float VposX, VposY;
	float r, g, b;

	virtual void draw();
	void tick();
	void drawAsteroide();
	bool isCollidedMissile(Missile *missile);
	bool isCollidedVaisseau(Vaisseau *vaisseau);
	bool heFreed(float x);

};