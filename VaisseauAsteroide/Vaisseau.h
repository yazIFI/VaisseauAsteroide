#pragma once
#include "GraphicPrimitives.h"
#include "Case.h"
#include "Missile.h"
#include "Engin.h"

class Vaisseau :public Engin{

private:
	float posX2, posY2, posX3, posY3;
	float r, g, b;
	float speedMissile;
	float prix;

public:
	int dimens;
	Vaisseau();
	~Vaisseau();
	std::vector<Missile *> *missilesV = new std::vector <Missile * >;
	Vaisseau(float posX1_, float posY1_, float r_, float g_, float b_, Missile *missile_ = nullptr) :
		Engin(posX1_,posY1_), posX2(posX), posY2(posY + 0.16), posX3(posX + 0.16), posY3(posY + 0.08), r(r_), g(g_), b(b_),
		mis(missile_), speedMissile(0.0)
	{
		missilesV->push_back(mis);
	}
	
	Missile *mis;
	virtual void draw();
	//Getter
	virtual float getPosX();
	virtual float getPosY();
	float getPosX2();
	float getPosY2();
	float getPosX3();
	float getPosY3();
	virtual float getVposX();
	virtual float getVposY();
	float getR();
	float getG();
	float getB();
	float getSpeedMissile();
	int getPrice();
	//Setter
	virtual void setPosX(float newX);
	virtual void setPosY(float newY);
	void setPosX2(float newX);
	void setPosY2(float newY);
	void setPosX3(float newX);
	void setPosY3(float newY);
	void setR(float newR);
	void setG(float newG);
	void setB(float newB);
	virtual void setVposX(float vPos);
	virtual void setVposY(float vPos);
	void setSpeedMissile(int newSpeed);
	void setPrice(int newPrice);
	static void reset(std::vector<Vaisseau *> *vaisseaux);
	
	virtual void tick();
};