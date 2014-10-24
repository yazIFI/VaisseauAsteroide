#include <string>
#include "stdio.h"
#include "stdlib.h"
#include "MyGraphicEngine.h"
#include "Engine.h"
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
#include <time.h>
#include "MyControlEngine.h"
#include "DimensionWindow.h"


#define PI 3.141592653589
std::vector<float> *vxTest = new std::vector<float>;
std::vector<float> *vyTest = new std::vector<float>;

using namespace std;

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
int afficheStart = 0;
int choice = 0;
char *priceS = new char[10];
DWORD penalTime = GetTickCount();
std::vector<Vaisseau * > *choixVaisseau ;

void MyGraphicEngine::Draw(){
	/*si le joueur ne choisie aucun niveau il est affecté directement au niveau1*/
	if (Part::getLevel() == 0){
		Part::setLevel(1);
	}

	/*si le temps du jeux est ecoulé , 
	on affiche le message de la fin du partie*/

	Part::partieFnished();



	choixVaisseau = new std::vector < Vaisseau * >;
	Dame::draw(cases);
	
	listA.drawChoiceAst();

	
		for (int i = 0; i < asteroides->size(); i++){
				(*asteroides)[i]->ListAsteroides::draw((*asteroides)[i]->getPosX(), (*asteroides)[i]->getPosY(), (*asteroides)[i]->getR(),
					(*asteroides)[i]->getG(), (*asteroides)[i]->getB(), choice);
				if ((*asteroides)[i]->heFreed()){
					life.verifyLife();
					swap((*asteroides)[i], asteroides->back());
					asteroides->pop_back();
					
				}
				
		}


	

	for (int i = 0; i < vaisseaux->size(); i++){
		(*vaisseaux)[i]->draw();
		for (int j = 1; j < (*vaisseaux)[i]->missilesV->size(); j++){
			if ((*(*vaisseaux)[i]->missilesV)[j]->getPosX() >= 0.8){
				swap((*(*vaisseaux)[i]->missilesV)[j], (*vaisseaux)[i]->missilesV->back());
				(*vaisseaux)[i]->missilesV->pop_back();
			}
			for (int k = 0; k < asteroides->size(); k++){
				
				 if (collision->isItTheSameBox((*asteroides)[k], (*vaisseaux)[i])
					&& (*asteroides)[k]->isCollidedVaisseau((*vaisseaux)[i])){
						swap((*asteroides)[k], asteroides->back());
						swap((*vaisseaux)[i], vaisseaux->back());
						asteroides->pop_back();
						vaisseaux->pop_back();
				}
				else if (collision->isItTheSameBox((*asteroides)[k], (*(*vaisseaux)[i]->missilesV)[j])){
					if ((*asteroides)[k]->isCollidedMissile((*(*vaisseaux)[i]->missilesV)[j])){
						swap((*(*vaisseaux)[i]->missilesV)[j], (*vaisseaux)[i]->missilesV->back());
						(*vaisseaux)[i]->missilesV->pop_back();
						(*asteroides)[k]->setR((*asteroides)[k]->getR() + ((*(*vaisseaux)[i]->missilesV)[j]->getHeight()*(15 / Part::getLevel())));
						(*asteroides)[k]->setG(0.0f);
						(*asteroides)[k]->setB((*asteroides)[k]->getB() - ((*(*vaisseaux)[i]->missilesV)[j]->getHeight()*(15 / Part::getLevel())));
						if (((*asteroides)[k]->getR() >= 1) && ((*asteroides)[k]->getB() <= 0)){
							swap((*asteroides)[k], asteroides->back());
							asteroides->pop_back();
							Player::setScore(Player::getScore() + 5);
						}
					}
					
				}
				
			}
			(*(*vaisseaux)[i]->missilesV)[j]->drawMissile();
		}
	}
	if ((asteroides->size() == 0) && (Part::getNbVague() >= (5 * Part::getLevel()))){

		ListAsteroides::isEmpty = true;
	}
	
	
	//GraphicPrimitives::drawText2D("V & A", -1.0, 0.9, 1.0f, 0.5f, 0.0f, 0.0);
	listV->fillListVaisseaux(choixVaisseau);

	for (int i = 0; i < choixVaisseau->size(); i++){
		_itoa_s((*choixVaisseau)[i]->getPrice(), priceS, 10,10);
		GraphicPrimitives::drawText2D(priceS, (*choixVaisseau)[i]->getPosX2(), (*choixVaisseau)[i]->getPosY2(), 0.0f, 0.0f, 0.0f, 1.0f);
		GraphicPrimitives::drawText2D(" eur", (*choixVaisseau)[i]->getPosX2()+0.05, (*choixVaisseau)[i]->getPosY2(), 0.0f, 0.0f, 0.0f, 1.0f);
		(*choixVaisseau)[i]->draw();
	}

	life.drawLifeLine();
	player.draw();
	delete choixVaisseau;

}

void MyGraphicEngine::reshape(int width, int height){
	DimensionWindow::setWidth(width);
	DimensionWindow::setHeight(height);
	cout << "width :" << DimensionWindow::getWidth() << endl;
	cout << "height :" << DimensionWindow::getHeight() << endl;

}




std::vector< Case *> MyGraphicEngine::getCase(){
	
	return *cases;
}



/*void MyGraphicEngine::polygon(float xc, float yc, float x, float y, int n) {

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
	GraphicPrimitives::drawOutlinedPolygone2D(*vxTest, *vyTest, 1.0, 0.0, 0.0, 1.0f);
}*/