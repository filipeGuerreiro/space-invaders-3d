#include "CameraThirdPerson.h"

CameraThirdPerson::CameraThirdPerson() : CameraPerspective() {};

void CameraThirdPerson::view() {
	Ship *n = Ship::getShip();
	this->setCoordinates(n->getX(), THIRD_Y, THIRD_Z);

	gluLookAt(_x, _y, _z,
			  _x, 1, 0,
			  0, 0, 1);

	if(!glIsEnabled(GL_LIGHTING))
		glEnable(GL_LIGHTING);
};