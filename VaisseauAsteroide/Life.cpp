#include "Life.h"
#include "GraphicPrimitives.h"


void Life::drawLifeLine(){
	GraphicPrimitives::drawFillRect2D(x,y,width,height, r, g, b, 1.0);
	GraphicPrimitives::drawText2D("life bar ", -1.0, 0.85, 1.0f, 1.0f, 1.0f, 1.0f);
}

void Life::verifyLife(){

	if (width <= 0.002){
		MessageBox(NULL, "You lost", "GAME OVER", MB_ICONSTOP);
		exit(0);
	}
	else{
		width -= 0.1;
		r += 0.4;
		b -= 0.4;
		std::cout << "width :" << width  << std::endl;
	}
}

