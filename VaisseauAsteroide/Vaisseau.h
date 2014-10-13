#pragma once
#include "GraphicPrimitives.h"
#include "Case.h"
#include "Missile.h"
#include "Price.h"
class Vaisseau :public Price{

private:
	float posX1, posY1, posX2, posY2, posX3, posY3;
	float r, g, b;

public:
	Vaisseau();
	~Vaisseau();
	Vaisseau(float posX1_, float posY1_, float r_, float g_, float b_, Missile *missile_ = nullptr) :
		posX1(posX1_), posY1(posY1_), posX2(posX1), posY2(posY1 + 0.16), posX3(posX1 + 0.16), posY3(posY1 + 0.08), r(r_), g(g_), b(b_),
		mis(missile_)
	{
		missilesV->push_back(mis);
	}
	std::vector<Missile *> *missilesV = new std::vector < Missile * > ;
	Missile *mis;
	void draw();
	//Getter
	float getPosX1();
	float getPosY1();
	float getPosX2();
	float getPosY2();
	float getPosX3();
	float getPosY3();
	float getR();
	float getG();
	float getB();
	//Setter
	void setposX1(float newX);
	void setposY1(float newY);
	void setposX2(float newX);
	void setposY2(float newY);
	void setposX3(float newX);
	void setposY3(float newY);
	void setR(float newR);
	void setG(float newG);
	void setB(float newB);

	void tick();
};