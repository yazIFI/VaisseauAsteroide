#include <string>
#include "stdio.h"
#include "stdlib.h"
//#include <gl/gl.h>
#include "MyGraphicEngine.h"
#include "Dame.h"
#include "Missile.h"
#include "Case.h"
#include "Life.h"
#include "Collision.h"
#include "ListVaisseau.h"
#include "ListAsteroides.h"
#include "Asteroide.h"
#include "Score.h"
#include "Player.h"
#define PI 3.141592653589
std::vector<float> *vxTest = new std::vector<float>;
std::vector<float> *vyTest = new std::vector<float>;

using namespace std;

MyGraphicEngine::MyGraphicEngine(){}

MyGraphicEngine::~MyGraphicEngine(){
	delete dames;
	delete missiles;
	delete asteroides;
	delete vaisseaux;
	
}
Life life;
Collision *collision;
ListVaisseau *listV;
ListAsteroides listA;
Player player("yezide");

int choice = 0;
bool tried = false;
int sc = 10;
char *priceS = new char[10];

void MyGraphicEngine::Draw(){
	player.score = sc;
	int price = 10;
	std::vector<Dame * > *dames = new std::vector < Dame * > ;
	std::vector<Vaisseau * > *choixVaisseau = new std::vector < Vaisseau * > ;
	float tempX = -1.0;
	float tempY = -1.0;
	float r = 1.0;
	float g = 1.0;
	float b = 1.0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			//colorer les cases 
			cases->push_back(new Case(tempX, tempY, r, g, b));
			if (r == 1.0){ r = 0.5; g = 0.5; b = 0.5; }
			else { r = 1.0; g = 1.0; b = 1.0; }
			tempX += 0.18;
		}
		tempX = -1.0;
		tempY += 0.18;
		if (r == 1.0){ r = 0.5; g = 0.5; b = 0.5; }
		else { r = 1.0; g = 1.0; b = 1.0; }
	}

	Dame::draw(cases);
	listA.drawChoiceAst();

	if ((asteroides->size() == 1)&& tried==false){
		choice = listA.boxChoice((*asteroides)[0]->posX, (*asteroides)[0]->posY);
		
		tried = true;
	}
	else{
		for (int i = 1; i < asteroides->size(); i++){
			(*asteroides)[i]->ListAsteroides::draw((*asteroides)[i]->posX, (*asteroides)[i]->posY, (*asteroides)[i]->r,
				(*asteroides)[i]->g, (*asteroides)[i]->b,choice);

		}
	}

	

	for (int i = 0; i < vaisseaux->size(); i++){
		(*vaisseaux)[i]->draw();
		for (int j = 0; j < (*vaisseaux)[i]->missilesV->size(); j++){
			(*(*vaisseaux)[i]->missilesV)[j]->drawMissile();
			for (int k = 0; k < asteroides->size(); k++){
				if (collision->isItTheSameBox((*asteroides)[k], (*vaisseaux)[i]) 
					&& (*asteroides)[k]->isCollidedVaisseau((*vaisseaux)[i])){
						life.width -= 0.2;
						swap((*asteroides)[k], asteroides->back());
						asteroides->pop_back();
				}
				else if (collision->isItTheSameBox((*asteroides)[k], (*(*vaisseaux)[i]->missilesV)[j])){
					if ((*asteroides)[k]->isCollidedMissile((*(*vaisseaux)[i]->missilesV)[j])){
						sc-=1;
						swap((*(*vaisseaux)[i]->missilesV)[j], (*vaisseaux)[i]->missilesV->back());
						(*vaisseaux)[i]->missilesV->pop_back();
						//delete (*vaisseaux)[i]->missilesV->back();
						(*asteroides)[k]->r += 0.2f;
						(*asteroides)[k]->g = 0.0f;
						(*asteroides)[k]->b -= 0.2f;
						if (((*asteroides)[k]->r >= 1) && ((*asteroides)[k]->b <=0)){
							swap((*asteroides)[k], asteroides->back());
							asteroides->pop_back();
						}
					}
				}
			}
		}
	}
	
	//GraphicPrimitives::drawText2D("V & A", -1.0, 0.9, 1.0f, 0.5f, 0.0f, 0.0);
	listV->fillListVaisseaux(choixVaisseau);

	for (int i = 0; i < choixVaisseau->size(); i++){
		(*choixVaisseau)[i]->setPrix(price);
		_itoa_s((*choixVaisseau)[i]->getPrix(), priceS, 10,10);
		GraphicPrimitives::drawText2D(priceS, (*choixVaisseau)[i]->getPosX2(), (*choixVaisseau)[i]->getPosY2(), 0.0f, 0.0f, 0.0f, 1.0f);
		GraphicPrimitives::drawText2D(" eur", (*choixVaisseau)[i]->getPosX2()+0.05, (*choixVaisseau)[i]->getPosY2(), 0.0f, 0.0f, 0.0f, 1.0f);
		(*choixVaisseau)[i]->draw();
		price += 10;
	}

	life.drawLifeLine();
	player.draw();
	player.Score::draw();
	delete choixVaisseau;
}

void MyGraphicEngine::reshape(int width, int height){
}




std::vector< Case *> MyGraphicEngine::getCase(){
	
	return *cases;
}



static void polygon(float xc, float yc, float x, float y, int n) {

	int lastx, lasty;
	float r = sqrt((x - xc) * (x - xc) + (y - yc) * (y - yc));
	float a = atan2(y - yc, x - xc);
	int i;

	for (i = 1; i <= n; i++) {
		a = a + PI * 2 / n;
		x = xc + (r * cos(a) / 6);
		y = yc + (r * sin(a) / 6);
		vxTest->push_back(x); vyTest->push_back(y);
	}
	GraphicPrimitives::drawFillPolygone2D(*vxTest, *vyTest, 1.0, 0.0, 0.0, 1.0f);
}