#include "Asteroide.h"


void Asteroide::draw(){
	std::vector<float> *vx = new std::vector<float>;
	std::vector<float> *vy = new std::vector<float>;

	vx->push_back(posX);
	vy->push_back(posY);
	vx->push_back(posX - 0.025);
	vy->push_back(posY);
	vx->push_back(posX - 0.05);
	vy->push_back(posY - 0.025);
	vx->push_back(posX - 0.05);
	vy->push_back(posY - 0.05);
	vx->push_back(posX - 0.025);
	vy->push_back(posY  - 0.075);
	vx->push_back(posX);
	vy->push_back(posY - 0.075);
	vx->push_back(posX + 0.025);
	vy->push_back(posY - 0.05);
	vx->push_back(posX + 0.025);
	vy->push_back(posY - 0.025);
	vx->push_back(posX);
	vy->push_back(posY);

	GraphicPrimitives::drawFillPolygone2D(*vx, *vy, r, g, b, 1.0f);// 0.6f, 0.5f, 1.0f);
	delete vx;
	delete vy;
}

void Asteroide::tick(){
	if (posX > -1.0){
		posX -= VposX;
	}
}

bool Asteroide::isCollided(float mposX, float aposX, float mposY, float aposY){
	if (((mposX - aposX) <= 0.01) && (((mposY - aposY) <= 0.00002))){
		return true;
	}
	return false;
}