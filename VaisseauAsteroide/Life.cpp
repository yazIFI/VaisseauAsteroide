#include "Life.h"
#include "GraphicPrimitives.h"

void Life::drawLifeLine(){
	GraphicPrimitives::drawFillRect2D(x,y,width,height,1.0f, 0.0f, 0.0f, 1.0);
}

bool Life::vrifyLife(){
	if (width <= 0.0){
		return true;
	}
	else{
		width -= 0.1;
		return false;
	}
}