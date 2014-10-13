#include "Score.h"
#include "Engine.h"

void Score::draw(){
	char *scoreString=new char[10];
	GraphicPrimitives::drawText2D("score :", -1.0, 0.85, 1.0f, 1.0f, 0.0f, 1.0f);
	_itoa_s(score, scoreString, 10, 10);
	GraphicPrimitives::drawText2D(scoreString, -0.85, 0.85, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("eur", -0.8, 0.85, 1.0f, 1.0f, 1.0f, 1.0f);
	delete scoreString;
}