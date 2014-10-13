#pragma once
#include "Score.h"
class Player :public Score{
private:
	char *name;
public:
	Player(char *name_):
		name(name_){}
	
	char * getName();

	char * setName(char * newName);

	virtual void draw();
};