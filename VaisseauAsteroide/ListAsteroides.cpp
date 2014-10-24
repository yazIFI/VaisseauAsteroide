#include "ListAsteroides.h"
#include "MyGraphicEngine.h"
#include "Asteroide.h"


bool ListAsteroides::isEmpty = false;

void ListAsteroides::draw1(float x, float y , float r , float g, float b){
	std::vector<float> *vx = new std::vector<float>;
	std::vector<float> *vy = new std::vector<float>;
	
	vx->push_back(x); vy->push_back(y); vx->push_back(x - 0.05); vy->push_back(y); vx->push_back(x - 0.1); vy->push_back(y - 0.05);
	vx->push_back(x- 0.1); vy->push_back(y - 0.1); vx->push_back(x - 0.05); vy->push_back(y - 0.15); vx->push_back(x); vy->push_back(y - 0.15);
	vx->push_back(x + 0.05); vy->push_back(y - 0.1); vx->push_back(x + 0.05); vy->push_back(y - 0.05); vx->push_back(x); vy->push_back(y);
	
	GraphicPrimitives::drawOutlinedPolygone2D(*vx, *vy, r, g, b, 1.0f);



	delete vx, vy;
}

void ListAsteroides::draw2(float posX, float posY,float r, float g, float b){
	std::vector<float> *vx = new std::vector<float>;
	std::vector<float> *vy = new std::vector<float>;
	
	vx->push_back(posX); vy->push_back(posY); vx->push_back(posX - 0.03); vy->push_back(posY - 0.03);
	
	vx->push_back(posX - 0.06); vy->push_back(posY - 0.03); vx->push_back(posX - 0.06); vy->push_back(posY - 0.06);
	
	vx->push_back(posX - 0.09); vy->push_back(posY - 0.09); vx->push_back(posX - 0.06); vy->push_back(posY - 0.12);
	
	vx->push_back(posX - 0.06); vy->push_back(posY - 0.15); vx->push_back(posX - 0.03); vy->push_back(posY - 0.15);
	
	vx->push_back(posX); vy->push_back(posY - 0.18); vx->push_back(posX + 0.03); vy->push_back(posY - 0.15);
	
	vx->push_back(posX + 0.06); vy->push_back(posY - 0.15); vx->push_back(posX + 0.06); vy->push_back(posY - 0.12);
	
	vx->push_back(posX + 0.09); vy->push_back(posY - 0.09); vx->push_back(posX + 0.06); vy->push_back(posY - 0.06);
	
	vx->push_back(posX + 0.06); vy->push_back(posY - 0.03); vx->push_back(posX + 0.03); vy->push_back(posY - 0.03);
	vx->push_back(posX); vy->push_back(posY);
	
	
	GraphicPrimitives::drawOutlinedPolygone2D(*vx, *vy, r, g, b, 1.0f);

	delete vx, vy;
}

void ListAsteroides::draw3(float x, float y, float r, float g, float b){

}

void ListAsteroides::drawChoiceAst(){
	char *nbVague = new char[10];
	_itoa_s(Part::getNbVague(), nbVague, 10, 10);
	GraphicPrimitives::drawFillRect2D(0.5, 0.8, 0.5, 0.2, 1.0, 1.0, 1.0);
	GraphicPrimitives::drawText2D("Pour lancer", 0.5, 0.95, 1.0f, 0.0f, 0.0f, 1.0f);
	GraphicPrimitives::drawText2D("les vagues d'asteroides", 0.5, 0.9, 1.0f, 0.0f, 0.0f, 1.0f);
	GraphicPrimitives::drawFillRect2D(0.5, 0.8, 0.3, 0.08, 0.0, 0.0, 1.0);
	GraphicPrimitives::drawText2D("CLIQUEZ ICI", 0.5, 0.82, 0.0f, 0.0f, 0.0f, 1.0f);
	GraphicPrimitives::drawText2D(nbVague, 0.85, 0.85, 0.0f, 0.0f, 0.0f, 1.0f);
}


int ListAsteroides::boxChoice(float x, float y){
	if (y >= 0.8){
		if ((x >= 0.8) && (x < 1.0)){
			return 1;
		}
		else if ((x >= 0.6) && (x < 0.8)){
			return 2;
			

		}
		else if ((x >= 0.4) && (x < 0.6)){
			return 3;

		}
		else{
			return 0;
		}
	}
	return 0;
}

void ListAsteroides::draw(float x, float y, float r, float g, float b,int choice){
	
	if (Part::getLevel() == 1){
		draw1(x,y,r,g,b);
	}
	
	else if (Part::getLevel() == 2){
		draw2(x,y,r,g,b);
	}
	else{
		draw2(x,y,1.0,0.0,0.0);
	}
}
