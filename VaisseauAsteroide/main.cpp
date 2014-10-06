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

	GraphicEngine * dge = new MyGraphicEngine(&dames, &asteroides,&missiles);
	GameEngine * dgme = new MyGameEngine(&dames, &asteroides,&missiles);
	ControlEngine * dce = new MyControlEngine(&dames,&missiles);

	e.setGraphicEngine(dge);
	e.setGameEngine(dgme);
	e.setControlEngine(dce);


	e.start();
	return 0;
}
