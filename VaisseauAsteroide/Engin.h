#pragma once
#include "GraphicPrimitives.h"

class  Engin{
public:
	float posX, posY;
	float VposX, VposY;
	Engin(float posX_ = 0.0f, float posY_ = 0.0f,float VposX_ = 0.03, float VposY_=0.0) :
		posX(posX_),
		posY(posY_),
		VposX(VposX_),
		VposY(VposY_)
	{}

	virtual float getPosX()=0;
	virtual float getPosY()=0;
	virtual float getVposX()=0;
	virtual float getVposY() = 0;
	virtual void  setPosX(float newPosX)=0;
	virtual void  setPosY(float newPosY)=0;
	virtual void setVposX(float newVposX)=0;
	virtual void setVposY(float newVposY) = 0;
	virtual void draw()=0;
	virtual void tick() = 0;
};