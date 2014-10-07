#include "MyControlEngine.h"
#include "MyGraphicEngine.h"
#include "Dame.h"
#include "Missile.h"

MyControlEngine::MyControlEngine(){}


float r1, g1, b1 = 1.0f;
void MyControlEngine::MouseCallback(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		float x1 = (x - 400) / 400.f;
		float y1 = (y - 300) / -300.f;  	
		//std::cout << "DEBEUG~~~~~~~~~~~~~~~~~~~~~ BEFOR" << x1 << ": " << y1 << std::endl;
		float ix = 0.8;
		float iy = 0.8;
		float w = 0.18;
		float h = 0.18;

		
		cout << "y1 " << y1 << endl << "x1 " << x1 << endl;
		if (y1 >= 0.8){
			if ((x1 >= -0.6) && (x1 <= -0.4)){
				r1 = 1.f;
				g1 = 0.5f;
				b1 = 0.0f;
				
			}
			else if ((x1 >= -0.4) && (x1 <= -0.2)){
				r1 = 0.0f;
				g1 = 0.0f;
				b1 = 0.5f;
			
			}
			else if((x1 >= -0.2) && (x1 <= 0.0)){
				r1 = 0.5f;
				g1 = 1.0f;
				b1 = 0.5f;
				
			}
			else{
				r1 = 0.0f;
				g1 = 0.0f;
				b1 = 0.0f;
			}

		}
		
		for (int k = 0; k<10; k++){
			if ((y1 <= iy) && (y1 >= (iy - h))){
				for (int j = 0; j<10; j++){
					if ((x1 <= ix) && (x1 >= (ix - w))){ 
						x1 = (ix - w); y1 = (iy - h); 
						if (iy <= 1.0){
							dames->push_back(new Dame(x1, y1, r1, g1, b1));
							
						}
						j = 10; k = 10; }

					ix -= w;
				}
			}
			iy -= h;
		}

	//	std::cout << "DEBEUG~~~~~~~~~~~~~~~~~~~~~" << x1 << ": " << y1 << std::endl;

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
				if ((x <= ix) && (x >= (ix - 0.4))){ return j + k; }

				ix -= 0.4;
			}
		}
		iy -= 0.4;
	}
	return -22;
}