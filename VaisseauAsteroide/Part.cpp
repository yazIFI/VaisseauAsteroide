#include "Part.h"
#include "Engine.h"
#include "ListAsteroides.h"

int Part::level = 0;
int Part::pastDt = 0;
int Part::nbVague = 0;
int Part::go = 0;
int Part::getLevel(){
	return level;
}

int Part::getNbVague(){
	return nbVague;
}

void Part::setLevel(int newLevel){
	Part::level = newLevel;
}

int Part::getPastDt(){
	return pastDt;
}

void Part::setPastDt(int newPastDt){
	pastDt = newPastDt;
}

void Part::setNbVague(int newNbVague){
	nbVague = newNbVague;
}

void Part::partieFnished(){
	if ( ListAsteroides::isEmpty){
		MessageBox(NULL, "La partie est terminée", 0, 0);
		exit(0);
	}
}