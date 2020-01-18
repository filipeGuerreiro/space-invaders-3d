#include "CameraFirstPerson.h"

CameraFirstPerson::CameraFirstPerson() : CameraPerspective() {};

void CameraFirstPerson::view() {
	Ship *n = Ship::getShip();
	this->setCoordinates(n->getX(), FIRST_Y, FIRST_Z);

	gluLookAt(_x, _y, _z,
			  _x, 1, 0,
			  0, 0, 1);

	if(!glIsEnabled(GL_LIGHTING))
		glEnable(GL_LIGHTING);
};