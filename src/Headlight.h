#pragma once
#include "LightSource.h"
#include "Ship.h"

class Headlight : public LightSource {
public:
	Headlight(float, float, float);
	void setCoordinates(float, float, float);
	void draw();

private:
	GLfloat _direction[3];
	Ship *_n;
};