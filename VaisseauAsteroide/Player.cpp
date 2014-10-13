#include "Player.h"
#include "Engine.h"

char * Player::getName(){
	return name;
}

char * Player::setName(char * newName){
	name = newName;
}


void Player::draw(){

	GraphicPrimitives::drawText2D("player :", -1.0, 0.92, 1.0f, 1.0f, 0.0f, 1.0f);
	GraphicPrimitives::drawText2D(name, -0.85, 0.92, 1.0f, 1.0f, 1.0f, 1.0f);
}