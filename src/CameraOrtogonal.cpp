#include "CameraOrtogonal.h"

CameraOrtogonal::CameraOrtogonal() : Camera() {};

void CameraOrtogonal::drawProjection() {
	float ratio = _w/_h;

	if(ratio > 1)
		glOrtho(-VERTICAL*ratio, VERTICAL*ratio, -HORIZONTAL, HORIZONTAL, -DEPTH, DEPTH);
	else
		glOrtho(-VERTICAL, VERTICAL, -HORIZONTAL/ratio, HORIZONTAL/ratio, -DEPTH, DEPTH);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if(glIsEnabled(GL_LIGHTING))
		glDisable(GL_LIGHTING);
};