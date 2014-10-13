#include "ListVaisseau.h"

void ListVaisseau::fillListVaisseaux(std::vector<Vaisseau *> *listV){
	GraphicPrimitives::drawFillRect2D(-0.62, 0.8, 0.6, 0.2, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawFillRect2D(-0.6, 0.8, 0.16, 0.2, 0.5f, 1.0f, 1.0f);
	GraphicPrimitives::drawFillRect2D(-0.4, 0.8, 0.16, 0.2, 0.5f, 1.0f, 1.0f);
	GraphicPrimitives::drawFillRect2D(-0.2, 0.8, 0.16, 0.2, 0.5f, 1.0f, 1.0f);
	listV->push_back(new Vaisseau(-0.6, 0.8, 1.0f, 0.5f, 0.0f));
	listV->push_back(new Vaisseau(-0.4, 0.8, 0.0f, 0.0f, 0.5f));
	listV->push_back(new Vaisseau(-0.2, 0.8, 0.5f, 1.0f, 0.5f));
	}