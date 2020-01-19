#pragma once

#include "Entity.h"

class LightSource : public Entity {

public:
	LightSource(float, float, float);
	void draw()=0;

protected:
	GLfloat _position[4];
	GLfloat _diffuse[4];
	GLfloat _specular[4];
	GLfloat _ambient[4];
}; 