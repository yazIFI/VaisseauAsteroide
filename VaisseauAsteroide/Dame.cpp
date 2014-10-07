#include "Dame.h"

using namespace std;


Dame::~Dame(){}
void Dame::draw(){
	GraphicPrimitives::drawFillRect2D(posX, posY, width, height, r, g, b);
}


void Dame::drawVaisseau(){
	GraphicPrimitives::drawFillTriangle2D(posX + 0.01, posY + 0.01, posX + 0.01, posY + 0.16, posX + 0.20, posY + 0.08, r, g, b);
}

void Dame::tick(){
	posX2 += (VposX + 0.05);
}

void Dame::drawMissile(){
		GraphicPrimitives::drawFillRect2D(posX2 + 0.08, posY + 0.07, width / 6, height / 6, 1.0f, 0.0f, 0.0f);
}

