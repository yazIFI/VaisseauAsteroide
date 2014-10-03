
#include "MyGameEngine.h"
#include "Asteroide.h"
#include "Dame.h"
#include "Missile.h"
#include <time.h>

MyGameEngine::~MyGameEngine(){
	delete dames;
	delete missiles;
	delete asteroides;
}

void MyGameEngine::idle(){
	for (int i = 0; i < dames->size(); i++) {
		(*dames)[i]->tick();
	}
	if (rand() < 200){
		asteroides->push_back(new Asteroide(1, 0.6));
		asteroides->push_back(new Asteroide(1, -0.5));
	}
	for (int i = 0; i < asteroides->size(); i++) {

		(*asteroides)[i]->tick();
		std::cout << rand() << std::endl;
	}


}