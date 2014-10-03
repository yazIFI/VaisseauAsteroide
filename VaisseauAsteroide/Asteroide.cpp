#include "Asteroide.h"


void Asteroide::draw(){
	std::vector<float> *vx = new std::vector<float>;
	std::vector<float> *vy = new std::vector<float>;
	float x = posX;
	float y = posY;

	vx->push_back(x);
	vy->push_back(y);
	vx->push_back(x - 0.05);
	vy->push_back(y);
	vx->push_back(x - 0.1);
	vy->push_back(y - 0.05);
	vx->push_back(x - 0.1);
	vy->push_back(y - 0.1);
	vx->push_back(x - 0.05);
	vy->push_back(y - 0.15);
	vx->push_back(x);
	vy->push_back(y - 0.15);
	vx->push_back(x + 0.05);
	vy->push_back(y - 0.1);
	vx->push_back(x + 0.05);
	vy->push_back(y - 0.05);
	vx->push_back(x);
	vy->push_back(y);

	GraphicPrimitives::drawFillPolygone2D(*vx, *vy, 1.0f, 0.6f, 0.5f, 1.0f);
	delete vx;
	delete vy;
}

void Asteroide::tick(){

	posX -= VposX;
}