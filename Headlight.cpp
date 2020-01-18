#include "Headlight.h"

Headlight::Headlight(float px, float py, float pz) : LightSource(px, py, pz) {

	_n = Ship::getShip();

	_position[0] = _position[1] = _position[2] = 0.0;
	_position[3] = 1.0; // local

	_direction[0] = 0.0;
	_direction[1] = 1.0;
	_direction[2] = 0.0;

	glLightfv(GL_LIGHT1, GL_POSITION, _position);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, _direction);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 20.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 30.0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, _diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, _specular);
	glLightfv(GL_LIGHT1, GL_AMBIENT, _ambient);

	/* switch to local viewpoint */
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
};

void Headlight::setCoordinates(float x, float y, float z) {
	_position[0] = x;
	_position[1] = y;
	_position[2] = z;
};

void Headlight::draw() {
	this->setCoordinates(_n->getX(), _n->getY()+5, _n->getZ());
	glLightfv(GL_LIGHT1, GL_POSITION, _position);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, _direction);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 20.0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, _diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, _specular);
	glLightfv(GL_LIGHT1, GL_AMBIENT, _ambient);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
};