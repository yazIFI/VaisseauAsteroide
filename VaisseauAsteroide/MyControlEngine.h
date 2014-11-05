#pragma once
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "Dame.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Vaisseau.h"
#include "Player.h"

class MyControlEngine :public ControlEngine{
	std::vector<Dame * > *dames;
	std::vector<Missile * > *missiles;// = new std::vector < Missile * > ;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;
	std::vector<Vaisseau *> *listVaisseaux = new  std::vector < Vaisseau * > ;
	Player player;

public:
	MyControlEngine();
	MyControlEngine(std::vector<Missile * > * missiles_, std::vector<Vaisseau *> *listVaisseaux_, std::vector<Asteroide *> *asteroides_,Player player_) :
		missiles(missiles_),
		listVaisseaux(listVaisseaux_),
		asteroides(asteroides_),
		player(player_){}
	~MyControlEngine();
	virtual void MouseCallback(int button, int state, int x, int y);
	
	void remplirVectVaisseaux(std::vector<Vaisseau *> *v, std::vector<Case *> *c, int nbcase);

	void addAsteroide(float x, float y);
	void listCases(std::vector<Case *> *c);
	void triangleSelected(float x, float y);
	/*verifie que la case selectionnée n'a pas déjà occupé*/
	bool notAlreadySelected(std::vector<Vaisseau *> *v, float x, float y);
	
};