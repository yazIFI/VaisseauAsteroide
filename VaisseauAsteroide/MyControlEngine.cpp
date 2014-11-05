#include "MyControlEngine.h"
#include "MyGraphicEngine.h"
#include "Dame.h"
#include "Missile.h"
#include "Vaisseau.h"
#include "Case.h"
#include "Score.h"
#include "Player.h"
#include "Part.h"
#include "DimensionWindow.h"

float r1, g1, b1 = 1.0f;

bool heSelected = false;
int numberSelection = 0;
std::vector<Case *> *listC = new std::vector < Case * > ;

void MyControlEngine::MouseCallback(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		/*gestion de la dimension de la fenetre*/
		float x1 = (x - (DimensionWindow::getWidth() / 2)) / (DimensionWindow::getWidth() / 2.f);
		float y1 = (y - (DimensionWindow::getHeight() / 2)) / (-DimensionWindow::getHeight() / 2.f);
		int caseChoisie;
		if ((x1 < 0.8) && (y1 < 0.8)){
			caseChoisie = ((int)((x1 + 1) / 0.18) + (10 * (int)((y1 + 1) / 0.18)));
		}
		triangleSelected(x1, y1);
		listCases(listC);
		remplirVectVaisseaux(listVaisseaux, listC, caseChoisie);
		addAsteroide(x1, y1);

	}
	
}

MyControlEngine::~MyControlEngine(){
	delete asteroides;
	delete listVaisseaux;
	delete listC;
	delete missiles;
}



void MyControlEngine::remplirVectVaisseaux(std::vector<Vaisseau *> *v,std::vector<Case *> *c, int nbCase){
	if (c->size() >= nbCase){
		if ((nbCase < 100)){
			if (heSelected){
				if (notAlreadySelected(v, ((*c)[nbCase]->getPosX()), ((*c)[nbCase]->getPosY()))){
					Missile miss((*c)[nbCase]->getPosX() + 0.08, (*c)[nbCase]->getPosY() + 0.07);
					v->push_back(new Vaisseau((*c)[nbCase]->getPosX(), (*c)[nbCase]->getPosY(), r1, g1, b1, &miss));
					Player::setMoney(Player::getMoney() - (numberSelection * 5));
					heSelected = false;
					(*v)[v->size() - 1]->dimens = numberSelection;
					(*v)[v->size() - 1]->setSpeedMissile(numberSelection);
					
				}
			}
			else{
				MessageBox(NULL, "veuillez choisir un vaisseau", 0, 0);
			}
		}
	}

}

void MyControlEngine::addAsteroide(float x, float y){
	if (((x >= 0.5) && (x<=0.8)) && ((y >= 0.8) && (y<=0.88)) && Part::go == 0){
		Part::go = 1;
	}
}

void MyControlEngine::listCases(std::vector<Case *> *c){
	float tempX = -1.0;
	float tempY = -1.0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			//colorer les cases 
			c->push_back(new Case(tempX, tempY, 0.0, 0.0, 0.0));

			tempX += 0.18;
		}
		tempX = -1.0;
		tempY += 0.18;

	}

}


void MyControlEngine::triangleSelected(float xx, float yy){
	if (yy >= 0.8){
		if ((xx >= -0.6) && (xx <= -0.4) && Player::getMoney() >= 5){
			r1 = 1.f;
			g1 = 0.5f;
			b1 = 0.0f;
			heSelected = true;
			numberSelection = 1;

		}
		else if ((xx >= -0.4) && (xx <= -0.2) && Player::getMoney() >= 10){
			r1 = 0.0f;
			g1 = 0.0f;
			b1 = 0.5f;
			heSelected = true;
			numberSelection = 2;


		}
		else if ((xx >= -0.2) && (xx <= 0.0) && Player::getMoney() >= 15){
			r1 = 0.5f;
			g1 = 1.0f;
			b1 = 0.5f;
			heSelected = true;
			numberSelection = 3;


		}
		else{
			if (xx <= 0.0 && xx >= -0.6){
				MessageBox(NULL, "Votre solde est insifusant pour acheter ce type de vaisseau", 0, 0);
			}
		}
		
	}
	
}

/*verifie que la case selectionnée n'est pas déjà occupé 
et empeche d'avoir plus d'un vaisseau sur la meme ligne
return bool*/

bool MyControlEngine::notAlreadySelected(std::vector<Vaisseau *> *v, float x, float y){
	for (int i = 0; i < v->size(); i++){
		if ((x == (*v)[i]->getPosX()) && (y == (*v)[i]->getPosY())){
			MessageBox(NULL, "case déjà selectionnée", 0, 0);
			return false;
		}
		if ((y == (*v)[i]->getPosY())){
			MessageBox(NULL, "Vaisseau existant sur la même ligne", 0, 0);
			return false;
		}
	}
	
	return true;
}
