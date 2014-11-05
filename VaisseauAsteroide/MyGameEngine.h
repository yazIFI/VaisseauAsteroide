#pragma once

#include "Engine.h"
#include "Missile.h"
#include "Dame.h"
#include "Asteroide.h"
#include "Vaisseau.h"


class MyGameEngine :public GameEngine {
public:
	int compte = 0;
	std::vector<Dame * > *dames = new std::vector < Dame * >;
	std::vector<Missile * > *missiles = new std::vector <Missile * >;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;
	std::vector<Vaisseau *> *vaisseaux = new std::vector < Vaisseau* > ;
	float coordAst[10];
	
	MyGameEngine();

	MyGameEngine(std::vector<Asteroide * > * asteroides_, std::vector<Missile *> * missilies_, std::vector<Vaisseau *> *vaisseaux_) :
		
		asteroides(asteroides_),
		missiles(missilies_),
		vaisseaux(vaisseaux_)

	{
		float n = -0.82;
		for (int i = 0; i < 10; i++){
			coordAst[i] = n;
			n += 0.18;
		}
	}
	~MyGameEngine();
	virtual void idle();

};
