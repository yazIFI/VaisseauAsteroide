#include "Life.h"
#include "GraphicPrimitives.h"


void Life::drawLifeLine(){
	GraphicPrimitives::drawFillRect2D(x,y,width,height, r, g, b, 1.0);
	GraphicPrimitives::drawText2D("life bar ", -1.0, 0.92, 1.0f, 1.0f, 1.0f, 1.0f);
}

void Life::verifyLife(){

	if (width <= 0.002){
		if (MessageBox(NULL, "You lost \n voulez vous refaire la partie", "GAME OVER", 0 + MB_ICONSTOP + MB_YESNO + MB_ICONQUESTION) == 6)
		{
			exit(0);
		}
	}
	else{
		width -= 0.1;
		r += 0.4;
		b -= 0.4;
	}
}

void Life::reset(){
	width = 0.3;
	r = 0.0;
	b = 1.0;
}

