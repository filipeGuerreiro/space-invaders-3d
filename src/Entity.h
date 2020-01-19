#ifndef _ENTIDADE_H
#define _ENTIDADE_H

#include <stdlib.h>
#include <time.h>	/* clock */
#include <math.h>

#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include "glut/include/GL/glut.h"
#endif

#include "soil/SOIL.h"
#pragma comment(lib,"soil/lib/libSOIL.a")


class Entity { 

protected:
	/* coordinates */
	float _x, _y, _z;
	/* state of the entity */
	bool _isAlive;
	// size of entity
	float _scale;

public:
	Entity();
	Entity(float px, float py, float pz);
	void setCoordinates(float, float, float);
	float getX();
	float getY();
	float getZ();
	float getScale();
	void setScale(float);
	void die();
	void reset();
	bool isAlive();
	virtual void draw() = 0;
};
#endif