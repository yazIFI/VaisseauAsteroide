#include "MyControlEngine.h"
#include "MyGraphicEngine.h"
#include "Dame.h"
#include "Missile.h"

MyControlEngine::MyControlEngine(){}
void MyControlEngine::MouseCallback(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		float x1 = (x - 400) / 400.f;
		float y1 = (y - 300) / -300.f;
		std::cout << "DEBEUG~~~~~~~~~~~~~~~~~~~~~ BEFOR" << x1 << ": " << y1 << std::endl;
		float ix = 1;
		float iy = 1;

		for (int k = 0; k<10; k++){
			if ((y1 <= iy) && (y1 >= (iy - 0.4))){
				for (int j = 0; j<10; j++){
					if ((x1 <= ix) && (x1 >= (ix - 0.2))){ x1 = (ix - 0.2); y1 = (iy - 0.4); dames->push_back(new Dame(x1, y1, 1.0, 0.0f, 1.0f)); j = 10; k = 10; }

					ix -= 0.2;
				}
			}
			iy -= 0.2;
		}
		std::cout << "DEBEUG~~~~~~~~~~~~~~~~~~~~~" << x1 << ": " << y1 << std::endl;

	}
}

MyControlEngine::~MyControlEngine(){
	delete asteroides;
}

int MyControlEngine::change(float x, float y){
	float ix = 1;
	float iy = 1;

	for (int k = 0; k<5; k++){
		if ((y <= iy) && (y >= (iy - 0.4))){
			for (int j = 0; j<5; j++){
				if ((x <= ix) && (x >= (ix - 0.4))){ std::cout << " j :" << x << "k :" << y << std::endl; return j + k; }

				ix -= 0.4;
			}
		}
		iy -= 0.4;
	}
	return -22;
}