#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "MyControlEngine.h"
#include "Dame.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Case.h"
#include "Vaisseau.h"

using namespace std;

class MyGraphicEngine :public GraphicEngine {

	char str[10];
public:
	std::vector<Case * > *cases = new std::vector < Case * >;
	std::vector<Dame * > *dames = new std::vector < Dame * >;
	std::vector<Missile * > *missiles = new std::vector < Missile * >;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;
	std::vector<Vaisseau *> *vaisseaux = new std::vector < Vaisseau * > ;


	int col;
	MyGraphicEngine();

	MyGraphicEngine(std::vector<Dame *> * dames_, std::vector<Asteroide * > * asteroides_, std::vector<Missile *> * missiles_,std::vector<Vaisseau *> * vaisseaux_) :
		dames(dames_),
		asteroides(asteroides_),
		missiles(missiles_),
		vaisseaux(vaisseaux_)
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
	std::vector< Case *> getCase();


};


