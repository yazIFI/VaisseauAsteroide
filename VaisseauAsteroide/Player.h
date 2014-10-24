#pragma once
#include "Score.h"
class Player :public Score{
private:
	char *name;
	static int score;
	
public:
	Player(char *name_):
		name(name_){}

	char * getName();
	void setName(char * newName);
	static int	 getScore();
	static void setScore(int newScore);
	virtual void draw();
};