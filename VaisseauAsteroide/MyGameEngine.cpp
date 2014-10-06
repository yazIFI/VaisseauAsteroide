#include "MyGameEngine.h"
#include "Asteroide.h"
#include "Dame.h"
#include "Missile.h"
#include <time.h>

using namespace std;

MyGameEngine::~MyGameEngine(){
	delete dames;
	delete missiles;
	delete asteroides;
}

void MyGameEngine::idle(){
	
	for (int i = 0; i < dames->size(); i++) {

		if (rand() < 3000){
			missiles->push_back(new Missile((*dames)[i]->posX+0.04, (*dames)[i]->posY+0.07));
		}
		(*dames)[i]->tick();
	}
	if (rand() < 200){
		asteroides->push_back(new Asteroide(1, ((float)(rand() % 10)) / 10));
		asteroides->push_back(new Asteroide(1, ((float)(rand() % 10)) / 10));
	}

	for (int i = 0; i < asteroides->size(); i++) {
		(*asteroides)[i]->tick();
	}
	for (int i = 0; i < missiles->size(); i++){
		(*missiles)[i]->tick();		
	}
	


}