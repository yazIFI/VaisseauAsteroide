#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Dame.h"
#include "Missile.h"
#include "Asteroide.h"

using namespace std;

class MyGraphicEngine :public GraphicEngine {

	char * str;
public:
	std::vector<Dame * > *dames = new std::vector < Dame * >;
	std::vector<Missile * > *missiles = new std::vector < Missile * >;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;

	int col;
	MyGraphicEngine();

	MyGraphicEngine(std::vector<Dame *> * dames_, std::vector<Asteroide * > * asteroides_, std::vector<Missile *> * missiles_) :
		dames(dames_),
		asteroides(asteroides_),
		missiles(missiles_)
	{
		if (MessageBox(NULL, "Voulez vous un vaisseau Bleu?", "CHOIX DE LA COULEUR DU VAISSEAU", 0 + MB_YESNO + MB_ICONQUESTION) == 6)
		{
			cout << "vous avez choisie un vaisseau de couleur bleu :) " << endl;
		}
	}
	~MyGraphicEngine();

	float x, y, w, h, r, g, b;
	virtual void Draw();
	void color();
	void traceRedLine();
	virtual void reshape(int width, int height);


};


