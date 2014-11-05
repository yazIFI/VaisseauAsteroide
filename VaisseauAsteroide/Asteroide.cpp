#include "Asteroide.h"
#include "Part.h"

float Asteroide::getPosX(){
	return posX;
}
float Asteroide::getPosY(){
	return posY;
}
float Asteroide::getVposX(){
	return VposX;
}
float Asteroide::getVposY(){
	return VposY;
}
float Asteroide::getR(){
	return r;
}
float Asteroide::getG(){
	return g;
}
float Asteroide::getB(){
	return b;
}
void  Asteroide::setPosX(float newPosX){
	posX = newPosX;
}
void  Asteroide::setPosY(float newPosY){
	posY = newPosY;
}
void Asteroide::setVposX(float newVposX){
	VposX = newVposX;
}
void Asteroide::setVposY(float newVposY){
	VposY = newVposY;
}
void Asteroide::setR(float newR){
	r = newR;
}
void Asteroide::setG(float newG){
	g = newG;
}
void Asteroide::setB(float newB){
	b = newB;
}

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


bool Asteroide::isCollidedMissile(Missile *missile){
	if ((abs((this->posX - missile->getPosX())) <= 0.12)){
		return true;
	}
	return false;
}
bool Asteroide::isCollidedVaisseau(Vaisseau *vaisseau){
	if ((abs(vaisseau->getPosX3() - posX) <= 0.12)){
		return true;
	}
	return false;
}
bool Asteroide::heFreed(){
	if (getPosX() <= -0.9){
		return true;
	}
	return false;
}

void Asteroide::tick(){
	float step;
	/*if (Part::getLevel()>1){
		posX -= (VposX*Part::getLevel());
	}*/
	posX -= 0.003;
	//posY = (float)(rand() % 10) / 10;
}

void Asteroide::reset(std::vector<Asteroide *> *asteroides){
		asteroides->clear();
}