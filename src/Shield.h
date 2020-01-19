#ifndef _ESCUDO_H
#define _ESCUDO_H

#include "Material.h"

class Shield : public Material { 

public:
	Shield(float, float, float);
	void deplete();
	void draw();
	void reset();

private:
	int _life;
};
#endif