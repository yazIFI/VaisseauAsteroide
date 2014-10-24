#pragma once
#include "GraphicPrimitives.h"
#include "Missile.h"
#include "Vaisseau.h"
#include "ListAsteroides.h"

class Asteroide :public ListAsteroides{

private:
	float posX, posY;
	float VposX, VposY;
	float r, g, b;
	int niveau;

public:
	Asteroide();

	Asteroide(float posX_ = 0.0f, float posY_ = 0.0f) :
		posX(posX_), posY(posY_), VposX(0.003f), VposY(0.02f),
		r(.0f), g(0.0f), b(1.0f), niveau(1)
	{}

	~Asteroide();


	float getPosX();
	float getPosY();
	float getVposX();
	float getVposY();
	float getR();
	float getG();
	float getB();
	void  setPosX(float newPosX);
	void  setPosY(float newPosY);
	void setVposX(float newVposX);
	void setVposY(float newVposY);
	void setR(float newR);
	void setG(float newG);
	void setB(float newB);

	virtual void draw();
	void tick();
	void drawAsteroide();
	bool isCollidedMissile(Missile *missile);
	bool isCollidedVaisseau(Vaisseau *vaisseau);
	bool heFreed();

};