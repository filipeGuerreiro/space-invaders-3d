#pragma once
#include "Material.h"
#include "ParticlesManager.h"

#define N_INIT_X 0.0
#define N_INIT_Y -40.0
#define N_INIT_Z 0.0
#define MOVE_DIST 3
#define LEFT_WALL -45
#define RIGHT_WALL 45

#define RED 1.0
#define GREEN 1.0
#define BLUE 1.0

class Ship : public Material {

public:
	static Ship *getShip();
	ParticlesManager *getExplosion();
	void draw();
	void drawExplosion();
	void moveLeft();
	void moveRight();
	void die();
	void updateExplosion(int);

private:
	static Ship* _ship;
	ParticlesManager *_explosion;
	Ship(float, float, float);
};