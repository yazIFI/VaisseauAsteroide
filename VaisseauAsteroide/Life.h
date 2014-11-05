#pragma once

class Life{
public:
	Life::Life(float x_=-1.0, float y_=0.97, float width_=0.3, float height_=0.05,float r_=0.0f,float g_=0.0f,float b_=1.0f):
	x(x_),y(y_),width(width_),height(height_),r(r_),g(g_),b(b_){}

	float x, y, width, height,r,g,b;
	void drawLifeLine();
	void verifyLife();
	void reset();
};