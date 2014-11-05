#pragma once
class A {
protected:
	int x;
public:

	A(int x_=0):
		x(x_)
	{}


	

	virtual int getX()=0;
	virtual void setX(int newX)=0;

};

