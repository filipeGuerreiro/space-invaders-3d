#pragma once

#include <math.h>
#include "Material.h"

#define AMOUNT 600
#define SIZE 0.5

typedef struct {
	//int texture;

	float position[3];
	float velocity[3];
	float color[3];

	float scale;
	float lifespan;	
} Particle;

class ParticlesManager {
	
private:
	Particle _particles[AMOUNT];
	bool _isRunning;
	int _size;
	float _time;
	GLfloat _amb[4];
	GLfloat _dif[4];
	static GLfloat _spec[];
	static const GLfloat _shine[];

public:
	ParticlesManager();
	bool isRunning();
	float getTime();
	void setTime(float);
	void isRunning(bool);
	void init(Material *);
	void update(Material *, float);
	void draw();
};