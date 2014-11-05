#pragma once

class ListAsteroides{	

public:
	void draw1(float x, float y, float r, float g, float b);
	void draw2(float x, float y, float r, float g, float b);
	void draw3(float x, float y, float r, float g, float b);
	void polygone(float x, float y, float r, float g, float b, int n,bool fill);
	void losange(float x, float y, float r, float g, float b);
	void drawChoiceAst();
	int boxChoice(float x, float y);
	virtual void draw(float x, float y, float r, float g, float b,int choice);
	static bool isEmpty;

};