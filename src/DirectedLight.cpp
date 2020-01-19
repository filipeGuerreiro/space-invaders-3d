#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(float px, float py, float pz) : LightSource(px, py, pz) {
	_position[0] = 0.0;
	_position[1] = 1.0;
	_position[2] = 1.0;
	_position[3] = 0.0; // nao-local

	glLightfv(GL_LIGHT0, GL_POSITION, _position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, _diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, _specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, _ambient);
};

void DirectionalLight::draw() {
};