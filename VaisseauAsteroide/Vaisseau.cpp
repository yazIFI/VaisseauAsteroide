#include "Vaisseau.h"



void Vaisseau::draw(){
	GraphicPrimitives::drawFillTriangle2D(posX1, posY1, posX2, posY2, posX3, posY3, r, g, b);
}

Vaisseau::~Vaisseau(){
	//delete missilesV;
}

//Getter
float Vaisseau::getPosX1(){
	return posX1;
}
float Vaisseau::getPosY1(){
	return posY1;
}
float Vaisseau::getPosX2(){
	return posX2;
}
float Vaisseau::getPosY2(){
	return posY2;
}
float Vaisseau::getPosX3(){
	return posX3;
}
float Vaisseau::getPosY3(){
	return posY3;
}
float Vaisseau::getR(){
	return r;
}
float Vaisseau::getG(){
	return g;
}
float Vaisseau::getB(){
	return b;
}

//Setter
void Vaisseau::setposX1(float newX){
	posX1 = newX;
}
void Vaisseau::setposY1(float newY){
	posX1 = newY;
}
void Vaisseau::setposX2(float newX){
	posX2 = newX;
}
void Vaisseau::setposY2(float newY){
	posX2 = newY;
}
void Vaisseau::setposX3(float newX){
	posX3 = newX;
}
void Vaisseau::setposY3(float newY){
	posX3 = newY;
}

void Vaisseau::setR(float newR){
	r = newR;
}
void Vaisseau::setG(float newG){
	g = newG;
}
void Vaisseau::setB(float newB){
	b = newB;
}

void Vaisseau::tick(){
	for (int i = 0; i < missilesV->size(); i++){
		(*missilesV)[i]->posX += 0.1;
	}
}
