#include <iostream>
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Engin.h"

#include "A.h"
#include "B.h"
#include "C.h"

#include <stdio.h>

int main(int argc, char * argv[])
{
	
	B b(1);
	
	std::vector<B *> *a = new std::vector < B * > ;
	a->push_back(new B(20));
	a->push_back(new B(30));
	a->push_back(new B(40));
	Engine e(argc, argv);

	std::vector<Dame *> dames;
	std::vector<Asteroide *> asteroides;
	std::vector<Missile *> missiles;
	std::vector<Vaisseau *> vaisseaux;
	Player player("player1");
	GraphicEngine * dge = new MyGraphicEngine(&asteroides, &missiles, &vaisseaux, player);
	GameEngine * dgme = new MyGameEngine(&asteroides, &missiles, &vaisseaux);
	ControlEngine * dce = new MyControlEngine(&missiles, &vaisseaux, &asteroides, player);

	e.setGraphicEngine(dge);
	e.setGameEngine(dgme);
	e.setControlEngine(dce);
	e.start(); 
	
	for (int i = 0; i < a->size(); i++){
		std::cout << (*a)[i]->getX() << std::endl;
	}
	
	system("pause");
	return 0;
}
