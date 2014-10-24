#pragma once
//#include "Asteroide.h"
class ListAsteroides{	

public:
	void draw1(float x, float y, float r, float g, float b);
	void draw2(float x, float y, float r, float g, float b);
	void draw3(float x, float y, float r, float g, float b);
	void drawChoiceAst();
	int boxChoice(float x, float y);
	virtual void draw(float x, float y, float r, float g, float b,int choice);
	static bool isEmpty;

};