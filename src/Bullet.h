#ifndef _BALA_H
#define _BALA_H

#include <windows.h>
#include <mmsystem.h>
#include "Shield.h"
#include "Ship.h"

#define UPPER_Y 45

#define BULLET_TRAVEL 2

class Bullet : public Material {
public:
	void draw();
	Bullet();
	Bullet(float x, float y, float z);
	void move();
	void fire();

private:
	Ship *_n;
};
#endif