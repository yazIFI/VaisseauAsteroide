#include "MyControlEngine.h"
#include "MyGraphicEngine.h"
#include "Dame.h"
#include "Missile.h"
#include "Vaisseau.h"
#include "Case.h"
#include "Score.h"
MyControlEngine::MyControlEngine(){}

float r1, g1, b1 = 1.0f;
int herewego = 0;
int score = 10;
std::vector<Case *> *listC = new std::vector < Case * > ;

void MyControlEngine::MouseCallback(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		float x1 = (x - 400) / 400.f;
		float y1 = (y - 300) / -300.f;

		int caseChoisie = ((int)((x1 + 1) / 0.18) + (10 * (int)((y1 + 1) / 0.18)));
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
		if (nbCase <= 100 && (*c)[nbCase]->getPosX() < 0.7){
			v->push_back(new Vaisseau((*c)[nbCase]->getPosX(), (*c)[nbCase]->getPosY(), r1, g1, b1,
				new Missile((*c)[nbCase]->getPosX() + 0.08, (*c)[nbCase]->getPosY() + 0.07)));
			
		}
	}

}

void MyControlEngine::addAsteroide(float x, float y){
	if ((x >= 0.2) && (y >= 0.8) && herewego == 0){
		asteroides->push_back(new Asteroide(x, y));
		herewego += 1;
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
		if ((xx >= -0.6) && (xx <= -0.4)){
			r1 = 1.f;
			g1 = 0.5f;
			b1 = 0.0f;

		}
		else if ((xx >= -0.4) && (xx <= -0.2)){
			r1 = 0.0f;
			g1 = 0.0f;
			b1 = 0.5f;

		}
		else if ((xx >= -0.2) && (xx <= 0.0)){
			r1 = 0.5f;
			g1 = 1.0f;
			b1 = 0.5f;

		}
		else{
			r1 = 0.0f;
			g1 = 0.0f;
			b1 = 0.0f;
		}

	}
}