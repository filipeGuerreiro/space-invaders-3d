#include "LightSource.h"

LightSource::LightSource(float px, float py, float pz) : Entity(px, py, pz) {
	
	_diffuse[0] = 1.0;
	_diffuse[1] = 1.0;
	_diffuse[2] = 1.0;
	_diffuse[3] = 1.0;

	_specular[0] = 0.2;
	_specular[1] = 0.2;
	_specular[2] = 0.2;
	_specular[3] = 1.0;

	_ambient[0] = 0.8;
	_ambient[1] = 0.8;
	_ambient[2] = 0.8;
	_ambient[3] = 1.0;
};