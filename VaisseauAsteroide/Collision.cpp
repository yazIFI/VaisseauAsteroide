#include "Collision.h"


bool Collision::isItTheSameBox(Asteroide *ast, Missile *miss){
	if ((miss->posY < ast->posY) && (miss->posY >= (ast->posY - 0.18))){
		return true;
	}
	return false;
}


bool Collision::isItTheSameBox(Asteroide *ast, Vaisseau *vais){
	if ((vais->getPosY1() < ast->posY) && (vais->getPosY1() >= (ast->posY - 0.18))){
		return true;
	}
	return false;
}