#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"

int main(int argc, char * argv[])
{

	Engine e(argc, argv);

	std::vector<Dame *> dames;
	std::vector<Asteroide *> asteroides;
	std::vector<Missile *> missiles;
	std::vector<Vaisseau *> vaisseaux;
	
	GraphicEngine * dge = new MyGraphicEngine(&dames, &asteroides,&missiles,&vaisseaux);
	GameEngine * dgme = new MyGameEngine(&dames, &asteroides,&missiles,&vaisseaux);
	ControlEngine * dce = new MyControlEngine(&dames, &missiles, &vaisseaux,&asteroides);
	
	e.setGraphicEngine(dge);
	e.setGameEngine(dgme);
	e.setControlEngine(dce);
	

	e.start();
	
	system("pause");
	return 0;
}
