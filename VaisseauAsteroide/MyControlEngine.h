#pragma once
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "Dame.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Vaisseau.h"

class MyControlEngine :public ControlEngine{
	std::vector<Dame * > *dames;
	std::vector<Missile * > *missiles;// = new std::vector < Missile * > ;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;
	std::vector<Vaisseau *> *listVaisseaux = new  std::vector < Vaisseau * > ;
	

public:
	
	MyControlEngine();
	MyControlEngine(std::vector<Dame * > * dames_, std::vector<Missile * > * missiles_, std::vector<Vaisseau *> *listVaisseaux_, std::vector<Asteroide *> *asteroides_) :
		dames(dames_),
		missiles(missiles_),
		listVaisseaux(listVaisseaux_),
		asteroides(asteroides_){}
	MyControlEngine(std::vector<Vaisseau * > * vaisseaux_) :listVaisseaux(vaisseaux_){}
	MyControlEngine(std::vector<Asteroide * > * asteroides_) :asteroides(asteroides_){}
	~MyControlEngine();

	virtual void MouseCallback(int button, int state, int x, int y);
	int incr;
	void remplirVectVaisseaux(std::vector<Vaisseau *> *v, std::vector<Case *> *c, int nbcase);

	void addAsteroide(float x, float y);
	void listCases(std::vector<Case *> *c);

	void triangleSelected(float x , float y);
};