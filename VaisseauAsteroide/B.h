#pragma once
#include "A.h"

class B :public A{
public:
	B(int x_=0):
		A(x_)
	{}

	void foo();
	virtual int getX();
	virtual void setX(int newX);

};