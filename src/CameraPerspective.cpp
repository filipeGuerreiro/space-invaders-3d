#include "CameraPerspective.h"

CameraPerspective::CameraPerspective() : Camera() {};

void CameraPerspective::drawProjection() {

	gluPerspective(FOVY, RATIO, Z_NEAR, Z_FAR);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	view();
};