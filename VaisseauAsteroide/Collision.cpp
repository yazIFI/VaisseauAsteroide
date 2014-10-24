#include "Collision.h"


bool Collision::isItTheSameBox(Asteroide *ast, Missile *miss){
	if ((miss->getPosY() < ast->getPosY()) && (miss->getPosY() >= (ast->getPosY() - 0.18))){
		return true;
	}
	return false;
}


bool Collision::isItTheSameBox(Asteroide *ast, Vaisseau *vais){
	if ((vais->getPosY2() < ast->getPosY()) && (vais->getPosY2() >= (ast->getPosY() - 0.10))){
		return true;
	}
	return false;
}