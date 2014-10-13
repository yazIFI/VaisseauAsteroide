#include "Missile.h"
#include "Asteroide.h"
void Missile::drawMissile(){
	GraphicPrimitives::drawFillRect2D(posX, posY, width, height, 1.0f, 0.0f, 0.0f);
}
Missile::~Missile(){}

void Missile::tick(){

	posX += 0.03;
}
