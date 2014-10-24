#pragma once
#include "GraphicPrimitives.h"

 class Missile{
 private:
	 float posX, posY, width, height;
	 float VposX;
	 static int dimensionMissile;
public:
	Missile();
	Missile(float posX_ = 0.0f, float posY_ = 0.0f,float width_=0.02,float height_=0.01,float VposX_=0.03) :
		posX(posX_),
		posY(posY_),
		width(width_),
		height(height_),
		VposX(VposX_)
	{}

	~Missile();


	float getPosX();
	float getPosY();
	float getVposX();
	float getWidth();
	float getHeight();
	static float getDimensionMissile();
	static void setDimensionMissile(int newDimension);
	void  setPosX(float newPosX);
	void  setPosY(float newPosY);
	void setVposX(float newVposX);
	void  setWidth(float newWidth);
	void setHeight(float newHeight);
	void drawMissile();
	void tick();

};