#ifndef _ALIEN_CAVEIRA_H
#define _ALIEN_CAVEIRA_H

#include "Alien.h"

class SkullAlien : public Alien {
	
public:
	SkullAlien(float px, float py, float pz);
	void draw();
	void firstAnimation();
	void secondAnimation();
};
#endif