#include "Dame.h"



//Dame::~Dame(){}
void Dame::draw(){
	GraphicPrimitives::drawFillRect2D(posX, posY, width, height, r, g, b);
}


void Dame::drawVaisseau(){
	int i = 0;
	GraphicPrimitives::drawFillTriangle2D(posX + 0.04, posY + 0.04, posX + 0.04, posY + 0.14, posX + 0.14, posY + 0.08, r, g, b);

}

void Dame::tick(){

	posX2 += (VposX + 0.1);
}

void Dame::drawMissile(){
	GraphicPrimitives::drawFillRect2D(posX2 + 0.04, posY + 0.07, width / 6, height / 6, 1.0f, 0.0f, 0.0f);
}