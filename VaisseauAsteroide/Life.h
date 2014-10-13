#pragma once

class Life{
public:
	Life::Life(float x_=-1.0, float y_=0.99, float width_=0.3, float height_=0.2):
	x(x_),y(y_),width(width_),height(height_){}

	float x, y, width, height;
	void drawLifeLine();
	bool vrifyLife();
};