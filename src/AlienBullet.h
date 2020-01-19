#pragma once

#include <windows.h>
#include <mmsystem.h>
#include "Alien.h"

#define LOWER_Y -45.0
#define BULLET_TRAVEL 2

class AlienBullet : public Material {
public:
	void draw();
	AlienBullet();
	AlienBullet(float x, float y, float z);
	Alien *getAlien();
	void setAlien(Alien *a);
	void move();
	void fire();
	bool isDepleted();
	void depleted();
	Alien *_a;

private:
	// cannot fire anymore
	bool _isDepleted;
};