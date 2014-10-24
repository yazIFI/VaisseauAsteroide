#include "Player.h"
#include "Engine.h"
#include "Engine.h"
#include "MyGraphicEngine.h"

int Player::score = 100; //score par defaut

char * Player::getName(){
	return name;
}

void Player::setName(char * newName){
	name = newName;
}

int	 Player::getScore(){
	return score;
}
void Player::setScore(int newScore){
	score = newScore;
}

void Player::draw(){
	GraphicPrimitives::drawText2D("player :", 0.0, 0.92, 1.0f, 1.0f, 0.0f, 1.0f);
	GraphicPrimitives::drawText2D(name, 0.2, 0.92, 1.0f, 1.0f, 1.0f, 1.0f);
	char *scoreString = new char[10];
	GraphicPrimitives::drawText2D("score :", 0.0, 0.85, 1.0f, 1.0f, 0.0f, 1.0f);
	_itoa_s(score, scoreString, 10, 10);
	GraphicPrimitives::drawText2D(scoreString, 0.2, 0.85, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("eur", 0.3, 0.85, 1.0f, 1.0f, 1.0f, 1.0f);
	
}