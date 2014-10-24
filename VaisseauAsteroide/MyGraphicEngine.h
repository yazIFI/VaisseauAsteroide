#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "MyControlEngine.h"
#include "Dame.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Case.h"
#include "Vaisseau.h"
#include "Player.h"
#include "Part.h"

using namespace std;

class MyGraphicEngine :public GraphicEngine {

	char str[10];
public:
	std::vector<Case * > *cases = new std::vector < Case * >;
	std::vector<Dame * > *dames = new std::vector < Dame * >;
	std::vector<Missile * > *missiles = new std::vector < Missile * >;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;
	std::vector<Vaisseau *> *vaisseaux = new std::vector < Vaisseau * > ;
	Player player;

	int col;
	int n = 0;
	MyGraphicEngine();

	MyGraphicEngine(std::vector<Dame *> * dames_, std::vector<Asteroide * > * asteroides_, std::vector<Missile *> * missiles_,std::vector<Vaisseau *> * vaisseaux_,Player player_) :
		dames(dames_),
		asteroides(asteroides_),
		missiles(missiles_),
		vaisseaux(vaisseaux_),
		player(player_)
	{
		if (MessageBox(NULL, "Niveau débutant", "CHOIX DE NIVEAU", 0 + MB_YESNO + MB_ICONQUESTION) == 6)
		{
			n = 1;
			Part::setLevel(n);
			Part::setPastDt(6000);
			MessageBox(NULL, "Le jeux va commencer . veuillez choisir vos vaisseaux", 0, 0);
			
		
		}
		else if (MessageBox(NULL, "Niveau intérmediaire", "CHOIX DE NIVEAU", 0 + MB_YESNO + MB_ICONQUESTION) == 6)
		{
			n = 2;
			Part::setLevel(n);
			Part::setPastDt(4000);
			MessageBox(NULL, "Le jeux va commencer . veuillez choisir vos vaisseaux", 0, 0);
		}
		else{
			MessageBox(NULL, "Vous avez choisi aucun niveau , veullez choisir un niveau", 0, 0);
			
		}

		
	}
	~MyGraphicEngine();

	float x, y, w, h, r, g, b;
	virtual void Draw();
	void color();
	void traceRedLine();
	virtual void reshape(int width, int height);
	void polygon(float xc, float yc, float x, float y, int n);
	std::vector< Case *> getCase();


};


