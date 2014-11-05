#pragma once
#include "GraphicPrimitives.h"
#include "Engin.h"

 class Missile :public Engin{
 private:
	 float width, height;
	 static int dimensionMissile;
public:
	Missile();
	Missile(float posX_ = 0.0f, float posY_ = 0.0f,float width_=0.02,float height_=0.01,float VposX_=0.03) :
		Engin(posX_,posY_,VposX_),
		width(width_),
		height(height_)
	{}

	~Missile();

	virtual float getPosX();
	virtual float getPosY();
	virtual float getVposX();
	virtual float getVposY();
	float getWidth();
	float getHeight();
	static float getDimensionMissile();
	static void setDimensionMissile(int newDimension);
	virtual void  setPosX(float newPosX);
	virtual void  setPosY(float newPosY);
	virtual void setVposX(float newVposX);
	virtual void setVposY(float newVposY);
	void  setWidth(float newWidth);
	void setHeight(float newHeight);
	void drawMissile();
	virtual void tick();
	virtual void draw();
};