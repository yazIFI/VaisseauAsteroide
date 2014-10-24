#include "MyGameEngine.h"
#include "Asteroide.h"
#include "Dame.h"
#include "Missile.h"
#include "Part.h"
#include <time.h>
#include <windows.h>

using namespace std;
DWORD startTime = GetTickCount();
DWORD previousTime = GetTickCount();
DWORD currentTime = GetTickCount();
int fire = 0;
int vague = 0;
MyGameEngine::~MyGameEngine(){
	delete dames;
	delete missiles;
	delete asteroides;
	delete vaisseaux;
}

void MyGameEngine::idle(){

	
	currentTime = GetTickCount();
	if ((currentTime - previousTime) >= 1){
		if ( (GetTickCount() > (startTime + Part::getPastDt())) && (Part::go > 0) && (Part::getNbVague()<(5 * Part::getLevel()))){
			asteroides->push_back(new Asteroide(1, coordAst[(rand() % 10)]));
			Part::setNbVague(Part::getNbVague() + 1);
			startTime = GetTickCount();

		}
		
		vague += 1;
		

		for (int i = 0; i < vaisseaux->size(); i++) {
			if ((fire % 31) == 0){
				((*vaisseaux)[i]->missilesV)->push_back(new Missile((*vaisseaux)[i]->getPosX3(), (*vaisseaux)[i]->getPosY3()));

				for (int k = 0; k < (*vaisseaux)[i]->missilesV->size(); k++){
					if ((*vaisseaux)[i]->dimens == 2){
						(*(*vaisseaux)[i]->missilesV)[k]->setHeight(0.02);
					}
					else if ((*vaisseaux)[i]->dimens == 3){
						(*(*vaisseaux)[i]->missilesV)[k]->setHeight(0.04);
						(*(*vaisseaux)[i]->missilesV)[k]->setWidth(0.05);
					}
					else{
						(*(*vaisseaux)[i]->missilesV)[k]->setHeight(0.01);
					}

				}
			}

			(*vaisseaux)[i]->tick();

			
		}
		fire += 1;


		for (int i = 0; i < asteroides->size(); i++) {

			(*asteroides)[i]->tick();
		}
		previousTime = currentTime;
	}
}
