#include "Dame.h"
#include "GraphicPrimitives.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Case.h"
using namespace std;


Dame::~Dame(){}
bool wedrawed = false;

void Dame::draw(std::vector<Case * > *cases){
	/*pour eviter de redessiner a chaque fois*/
	if (wedrawed == false){
		float tempX = -1.0;
		float tempY = -1.0;
		float r = 1.0;
		float g = 1.0;
		float b = 1.0;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				//colorer les cases 
				cases->push_back(new Case(tempX, tempY, r, g, b));
				if (r == 1.0){ r = 0.5; g = 0.5; b = 0.5; }
				else { r = 1.0; g = 1.0; b = 1.0; }
				tempX += 0.18;
			}
			tempX = -1.0;
			tempY += 0.18;
			if (r == 1.0){ r = 0.5; g = 0.5; b = 0.5; }
			else { r = 1.0; g = 1.0; b = 1.0; }
		}
		wedrawed = true;
	}
	
	GraphicPrimitives::drawFillRect2D(0.8, -1.0, 0.2, 1.8, 1.0, 0.0, 0.0);
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

