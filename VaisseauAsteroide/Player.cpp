#include "Player.h"
#include "Engine.h"
#include "MyGraphicEngine.h"
#include <sstream>
int Player::money = 30; //score par defaut

char * Player::getName(){
	return name;
}

void Player::setName(char * newName){
	name = newName;
}

int	 Player::getMoney(){
	return money;
}

void Player::setMoney(int newMoney){
	money = newMoney;
}

void Player::draw(){
	std::ostringstream o;
	GraphicPrimitives::drawText2D("player :", 0.0, 0.95, 1.0f, 1.0f, 0.0f, 1.0f);
	GraphicPrimitives::drawText2D(name, 0.16, 0.95, 1.0f, 1.0f, 1.0f, 1.0f);
	char *moneyString = new char[10];
	GraphicPrimitives::drawText2D("Money :", 0.0, 0.9, 1.0f, 1.0f, 0.0f, 1.0f);
	_itoa_s(getMoney(), moneyString, 10, 10);
	GraphicPrimitives::drawText2D(moneyString, 0.16, 0.9, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("eur", 0.25, 0.9, 1.0f, 1.0f, 1.0f, 1.0f);
}

void Player::reset(){
	setMoney(getMoney()+30);
}