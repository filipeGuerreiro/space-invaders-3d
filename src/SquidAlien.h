#ifndef _ALIEN_LULA_H
#define _ALIEN_LULA_H

#include "Alien.h"

class SquidAlien : public Alien {
	
public:
	SquidAlien(float, float, float);
	void draw();
	void firstAnimation();
	void secondAnimation();
};

#endif