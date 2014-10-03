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

	GraphicEngine * dge = new MyGraphicEngine(&dames, &asteroides);
	GameEngine * dgme = new MyGameEngine(&dames, &asteroides);
	ControlEngine * dce = new MyControlEngine(&dames);

	e.setGraphicEngine(dge);
	e.setGameEngine(dgme);
	e.setControlEngine(dce);


	e.start();
	return 0;
}
