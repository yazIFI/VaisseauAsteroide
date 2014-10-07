#include <string>
#include "stdio.h"
#include "stdlib.h"
//#include <gl/gl.h>
#include "MyGraphicEngine.h"
#include "Dame.h"
#include "Missile.h"

using namespace std;

MyGraphicEngine::MyGraphicEngine(){}

MyGraphicEngine::~MyGraphicEngine(){
	delete dames;
	delete missiles;
	delete asteroides;
}

void MyGraphicEngine::Draw(){

	std::vector<Dame * > *vaisseau = new std::vector < Dame * > ;
	char s[10];
	int compt = 0;
	r = 0.5f;
	g = 0.5f;
	b = 0.5f;
	w = 0.18;
	h = 0.18;
	x = -1;
	y = -1;
	//std::vector<Dame * > *damesposX = new std::vector < Dame * >;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
			_itoa_s(compt, s, 10);
			GraphicPrimitives::drawText2D(s, x, y, 0.0f, 0.7f, 1.0f);
			compt++;
			if (r < 1.0f){ r = 1.0f; g = 1.0f; b = 1.0f; }
			else{ r = 0.5f; g = 0.5f;  b = 0.5f; }
			x += w;
		}
		if (r < 1.0f){ r = 1.0f; g = 1.0f; b = 1.0f; }
		else{ r = 0.5f; g = 0.5f;  b = 0.5f; }
		x = -1;
		y += h;
	}

	for (int i = 0; i < dames->size(); i++) {

		(*dames)[i]->drawVaisseau();

	}
	for (int i = 0; i < asteroides->size(); i++){
		(*asteroides)[i]->draw();

		for (int j = 0; j < missiles->size(); j++){
			if ((*asteroides)[i]->isCollided((*missiles)[j]->posX, (*asteroides)[i]->posX, (*asteroides)[i]->posY, (*missiles)[j]->posY)){
				swap((*missiles)[j], missiles->back());
				(*missiles).pop_back();
				if ((*asteroides)[i]->posX < 0.5){
					(*asteroides)[i]->r -= 0.03f;
					if ((*asteroides)[i]->r < 0.0){
						swap((*asteroides)[i], asteroides->back());
						(*asteroides).pop_back();
						
						/*delete missiles->back();
						delete asteroides->back();*/
					}
				}
			}

			if ((*asteroides)[i]->heFreed((*asteroides)[i]->posX)){
				MessageBox(NULL, "Vous avez était touché", "Affranchissement Des Vaisseaux", 0 + MB_ICONQUESTION);

			}
		}

	}




	for (int i = 0; i < missiles->size(); i++){
		(*missiles)[i]->drawMissile();	
	}

	vaisseau->push_back(new Dame(-0.6, 0.8, 1.0f,0.5f,0.0f));
	vaisseau->push_back(new Dame(-0.4, 0.8, 0.0f, 0.0f, 0.5f));
	vaisseau->push_back(new Dame(-0.2, 0.8, 0.5f, 1.0f, 0.5f));

	for (int i = 0; i < vaisseau->size(); i++){
		(*vaisseau)[i]->drawVaisseau();
	}

	traceRedLine();

	delete(vaisseau);

}

void MyGraphicEngine::reshape(int width, int height){
}
void MyGraphicEngine::color(){
	r = 1.0f;
	g = 0.0f;
	b = 0.0f;
}

void MyGraphicEngine::traceRedLine(){
	color();
	GraphicPrimitives::drawFillRect2D(-1.0, 0.99, 2.0, 0.1, r, g, b, 1.0);
}


