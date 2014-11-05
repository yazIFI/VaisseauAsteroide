#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "MyControlEngine.h"
#include "Dame.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Case.h"
#include "Vaisseau.h"
#include "Player.h"
#include "Part.h"

#define CreateWindow CreateWindowA

HWND WINAPI CreateWindowEx(
	_In_      DWORD dwExStyle,
	_In_opt_  LPCTSTR lpClassName,
	_In_opt_  LPCTSTR lpWindowName,
	_In_      DWORD dwStyle,
	_In_      int x,
	_In_      int y,
	_In_      int nWidth,
	_In_      int nHeight,
	_In_opt_  HWND hWndParent,
	_In_opt_  HMENU hMenu,
	_In_opt_  HINSTANCE hInstance,
	_In_opt_  LPVOID lpParam
	);

using namespace std;

class MyGraphicEngine :public GraphicEngine {

	char str[10];
public:
	std::vector<Case * > *cases = new std::vector < Case * >;
	std::vector<Dame * > *dames = new std::vector < Dame * >;
	std::vector<Missile * > *missiles = new std::vector <Missile * >;
	std::vector<Asteroide *> *asteroides = new std::vector < Asteroide * >;
	std::vector<Vaisseau *> *vaisseaux = new std::vector < Vaisseau * > ;
	Player player;

	int col;
	int n = 0;
	MyGraphicEngine();

	MyGraphicEngine(std::vector<Asteroide * > * asteroides_, std::vector<Missile *> * missiles_, std::vector<Vaisseau *> * vaisseaux_, Player player_) :
		
		asteroides(asteroides_),
		missiles(missiles_),
		vaisseaux(vaisseaux_),
		player(player_)
	{
		/*HWND WINAPI CreateWindow(TEXT("edit"), TEXT("enter your name"), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			10, 10, 200, 100, HWND, (HMENU)1, NULL, NULL);*/
		MessageBox(NULL, "Veuillez choisir un niveau", 0, 0);

		if (MessageBox(NULL, "Niveau débutant", "CHOIX DE NIVEAU", 0 + MB_YESNO + MB_ICONQUESTION) == 6)
		{
			n = 1;
			Part::setLevel(n);
			Part::setPastDt(5000);
			
		
		}
		else if (MessageBox(NULL, "Niveau intérmediaire", "CHOIX DE NIVEAU", 0 + MB_YESNO + MB_ICONQUESTION) == 6)
		{
			n = 2;
			Part::setLevel(n);
			Part::setPastDt(7000);
		}
		else if (MessageBox(NULL, "Niveau expert", "CHOIX DE NIVEAU", 0 + MB_YESNO + MB_ICONQUESTION) == 6)
		{
			n = 3;
			Part::setLevel(n);
			Part::setPastDt(8000);
		}
		else{
			MessageBox(NULL, "Vous avez choisi aucun niveau , le niveau par defaut : 1", 0, 0);
			
		}

		MessageBox(NULL, "Le jeux va commencer . veuillez choisir vos vaisseaux \n et lancer les vagues d'asteroides", 0, 0);
	}
	~MyGraphicEngine();

	float x, y, w, h, r, g, b;
	virtual void Draw();
	void color();
	void traceRedLine();
	virtual void reshape(int width, int height);
	static void polygon(float xc, float yc, float x, float y, int n);
	std::vector< Case *> getCase();


};


