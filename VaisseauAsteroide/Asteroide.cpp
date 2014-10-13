#include "Asteroide.h"


void Asteroide::draw(){
	std::vector<float> *vx = new std::vector<float>;
	std::vector<float> *vy = new std::vector<float>;

	std::vector<float> *vx2 = new std::vector<float>;
	std::vector<float> *vy2 = new std::vector<float>;

	vx2->push_back(posX);vy2->push_back(posY);vx2->push_back(posX - 0.05);vy2->push_back(posY);vx2->push_back(posX - 0.1);vy2->push_back(posY - 0.05);
	vx2->push_back(posX - 0.1);vy2->push_back(posY - 0.1);vx2->push_back(posX - 0.1);vy2->push_back(posY - 0.15);vx2->push_back(posX);vy2->push_back(posY - 0.15);
	vx2->push_back(posX + 0.05);vy2->push_back(posY - 0.1);vx2->push_back(posX + 0.05);vy2->push_back(posY - 0.05);vx2->push_back(posX);vy2->push_back(posY);

	vx->push_back(posX);vy->push_back(posY);vx->push_back(posX - 0.03);vy->push_back(posY + 0.015);
	
	vx->push_back(posX - 0.03);vy->push_back(posY + 0.045);vx->push_back(posX - 0.06);vy->push_back(posY + 0.045);
	
	vx->push_back(posX - 0.075);vy->push_back(posY + 0.075);vx->push_back(posX-0.09);vy->push_back(posY + 0.045);
	
	vx->push_back(posX - 0.12);vy->push_back(posY + 0.045);vx->push_back(posX - 0.12);vy->push_back(posY + 0.015);
	
	vx->push_back(posX-0.15); vy->push_back(posY); vx->push_back(posX - 0.12); vy->push_back(posY - 0.015);

	vx->push_back(posX - 0.12); vy->push_back(posY - 0.045); vx->push_back(posX - 0.09); vy->push_back(posY - 0.045);

	vx->push_back(posX - 0.075); vy->push_back(posY - 0.06); vx->push_back(posX - 0.06); vy->push_back(posY - 0.045);

	vx->push_back(posX - 0.03); vy->push_back(posY - 0.045); vx->push_back(posX - 0.03); vy->push_back(posY - 0.015);

	vx->push_back(posX); vy->push_back(posY);

	GraphicPrimitives::drawFillPolygone2D(*vx2, *vy2, r, g, b, 1.0f);
	delete vx, vy, vx2, vy2;
}

void Asteroide::tick(){
		posX -= VposX;
		//posY = ((float)(rand() % 10) / 10);
}

bool Asteroide::isCollidedMissile(Missile *missile){
	if ((abs((this->posX - missile->posX)) <= 0.16)){
		return true;
	}
	return false;
}
bool Asteroide::isCollidedVaisseau(Vaisseau *vaisseau){
	if ((abs(vaisseau->getPosX1() - posX) <= 0.2) && 
		(((abs(posY - vaisseau->getPosY2()) == 0.16)) || ((abs(vaisseau->getPosY2() - posY) <= 0.16)))){
		
		return true;
	}
	return false;
}
bool Asteroide::heFreed(float x){
	if (x <= -1){
		return true;
	}
	return false;
}