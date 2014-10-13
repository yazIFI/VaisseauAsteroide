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
	delete vaisseaux;
}

void MyGameEngine::idle(){
		if (((rand() % 37) == 0) && (asteroides->size() >0)) {
			asteroides->push_back(new Asteroide(1 , coordAst[(rand() % 10)]));
		}
	
	
	for (int i = 0; i < vaisseaux->size(); i++) {
		if ((rand() % 2) == 0){
			((*vaisseaux)[i]->missilesV)->push_back(new Missile((*vaisseaux)[i]->getPosX3(), (*vaisseaux)[i]->getPosY3()));
		}
		(*vaisseaux)[i]->tick();
		
		
	}
	

	for (int i = 0; i < asteroides->size(); i++) {
		(*asteroides)[i]->tick();
	}
	for (int i = 0; i < missiles->size(); i++){
		(*missiles)[i]->tick();		
	}
	


}