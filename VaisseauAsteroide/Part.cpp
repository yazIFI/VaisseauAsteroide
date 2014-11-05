#include "Part.h"
#include "Engine.h"
#include "ListAsteroides.h"

int Part::level = 0;
int Part::pastDt = 0;
int Part::nbVague = 0;
int Part::go = 0;
bool Part::isUpdate = false;
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
			isUpdate = true;
	}
}

void Part::choiceToContinue(){
	if (MessageBox(NULL, "Passer au niveau supérieur", "CHOIX DE NIVEAU", 0 + MB_YESNO + MB_ICONQUESTION) == 6)
	{
		Part::setLevel((Part::getLevel() + 1));
	}
	else{
		MessageBox(NULL, "AU REVOIR", 0, 0);
		exit(0);
	}
}

void Part::reset(){
	Part::setNbVague(0);
	Part::isUpdate = false;
}
