#include "Missile.h"



Missile::~Missile(){}

void Missile::drawAsteroide(){
	GraphicPrimitives::drawFillRect2D(posX, posY, width, height, 1.0f, 0.0f, 0.0f);
}

void Missile::tick(){

	posX += VposX;
}