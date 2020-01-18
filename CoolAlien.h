#ifndef _ALIEN_FIXE_H
#define _ALIEN_FIXE_H

#include "Alien.h"

class CoolAlien : public Alien {
	
public:
	CoolAlien(float px, float py, float pz);
	void draw();
	void firstAnimation();
	void secondAnimation();
};
#endif