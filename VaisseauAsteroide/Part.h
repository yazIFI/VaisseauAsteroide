#pragma once

class Part{
private:
	static int level;
	static int pastDt;  //le coef du temps de nombre de vague lanc�es 
	static int nbVague; // la dur�e de chaque partie

public:
	static int go;
	static int getLevel();
	static void setLevel(int newLevel);
	static int getNbVague();
	static int getPastDt();
	static void setPastDt(int newPastDt);
	static void setNbVague(int newNbVague);
	static void partieFnished();
};