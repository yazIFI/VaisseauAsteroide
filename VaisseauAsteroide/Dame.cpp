#include "Dame.h"
#include "GraphicPrimitives.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Case.h"
using namespace std;


Dame::~Dame(){}


void Dame::draw(std::vector<Case * > *cases){
	GraphicPrimitives::drawFillRect2D(0.8, -1.0, 0.2, 1.8, 1.0, 0.0, 0.0);
	GraphicPrimitives::drawFillRect2D(0.4, 0.8, 0.6, 0.2, 1.0, 0.0, 1.0);
	for (int i = 0; i< cases->size();i++){
		(*cases)[i]->draw();

	}
}


void Dame::drawVaisseau(){
	GraphicPrimitives::drawFillTriangle2D(posX + 0.01, posY + 0.01, posX + 0.01, posY + 0.14, posX + 0.18, posY + 0.07, r, g, b);
}

void Dame::tick(){
	posX2 += (VposX + 0.05);
}

void Dame::drawMissile(){
		GraphicPrimitives::drawFillRect2D(posX2 + 0.08, posY + 0.07, width / 6, height / 6, 1.0f, 0.0f, 0.0f);
}

