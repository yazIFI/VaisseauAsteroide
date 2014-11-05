#include "B.h"
#include <iostream>

int B::getX(){
	return x;
}

void B::setX(int nx){
	x = nx+9;
}

void B::foo(){
	std::cout << "ok " << std::endl;
}