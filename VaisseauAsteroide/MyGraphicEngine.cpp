#include <string>
#include "stdio.h""
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

	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
	w = 0.2;
	h = 0.2;
	x = -1;
	y = -1;
	std::vector<Dame * > *damesposX = new std::vector < Dame * >;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
			if (r < 1.0f){ r = 1.0f; g = 1.0f; b = 1.0f; }
			else{ r = 0.0f; g = 0.0f;  b = 0.0f; }
			x += 0.2;
		}
		if (r < 1.0f){ r = 1.0f; g = 1.0f; b = 1.0f; }
		else{ r = 0.0f; g = 0.0f;  b = 0.0f; }
		x = -1;
		y += 0.2;
	}

	for (int i = 0; i < dames->size(); i++) {

		(*dames)[i]->drawVaisseau();
		(*dames)[i]->drawMissile();
		damesposX->push_back(new Dame((*dames)[i]->posX2, (*dames)[i]->posY, 1.0, 0.0f, 1.0f));
	}
	for (int i = 0; i < asteroides->size(); i++){
		(*asteroides)[i]->draw();
		if ((*asteroides)[i]->posX ==(*damesposX)[i]->posX2){//<= -0.55){
			(*asteroides).pop_back();
		}
	}

}

void MyGraphicEngine::reshape(int width, int height){
}
void MyGraphicEngine::color(){
	r = 1.0f;
	g = 0.0f;
	b = 0.0f;
}


