#pragma once
#include "GraphicPrimitives.h"
#include "Missile.h"
#include "Vaisseau.h"
#include "ListAsteroides.h"
#include "Engin.h"

class Asteroide :public Engin, public ListAsteroides{

private:
	float r, g, b;
	int niveau;

public:
	Asteroide();

	Asteroide(float posX_ = 0.0f, float posY_ = 0.0f) :
		Engin(posX_, posY_, 0.003, 0.02),
		r(.0f), g(0.0f), b(1.0f), niveau(1)
	{}

	~Asteroide();


	virtual float getPosX();
	virtual float getPosY();
	virtual float getVposX();
	virtual float getVposY();
	float getR();
	float getG();
	float getB();
	virtual void  setPosX(float newPosX);
	virtual void  setPosY(float newPosY);
	virtual void setVposX(float newVposX);
	virtual void setVposY(float newVposY);
	void setR(float newR);
	void setG(float newG);
	void setB(float newB);

	virtual void draw();
	virtual void tick();
	void drawAsteroide();
	bool isCollidedMissile(Missile *missile);
	bool isCollidedVaisseau(Vaisseau *vaisseau);
	bool heFreed();
	static void reset(std::vector<Asteroide *> *asteroides);

};