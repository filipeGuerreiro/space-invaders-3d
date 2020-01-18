#include "Shield.h"

Shield::Shield(float px, float py, float pz) : Material(px, py, pz) {
	_radius = 6;
	_life = 5;
	diffuse[0] = 0.124;
	diffuse[1] = 0.852;
	diffuse[2] = 0.0;
	diffuse[3] = 1.0;
	ambient[0] = 0.0124;
	ambient[1] = 0.0852;
	ambient[2] = 0.0;
	ambient[3] = 1.0;
};

void Shield::deplete() {
	if(_life == 0)
		this->die();
	diffuse[0] -= ambient[0]*1.5;
	diffuse[1] -= ambient[1]*1.5;

	_life--;
};

void Shield::reset() {
	diffuse[0] = 0.124;
	diffuse[1] = 0.852;
	_life = 5;
	_isAlive = true;
};

void Shield::draw() {
 glPushMatrix();
	if(glIsEnabled(GL_LIGHTING)) {
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	} else
		glColor3f(diffuse[0], diffuse[1], 0.0);
	glTranslatef(getX(), getY(), getZ());
	if(_debug)
		glutWireSphere(_radius, 10, 10);
	glScalef(1.0, 0.8, 2.0);
	// dome
	glPushMatrix();
		glTranslatef(0.0, 5.0, 0.0);
		createHexahedron(7.0, 1.0, 1.0, true, false, true, true);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 4.0, 0.0);
		createHexahedron(9.0, 1.0, 1.0, true, false, true, true);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 3.0, 0.0);
		createHexahedron(11.0, 1.0, 1.0, true, false, true, true);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 6.0, 0.0);
		createHexahedron(5.0, 1.0, 1.0, true, false, true, true);
	glPopMatrix();

	// center
	glPushMatrix();
		createHexahedron(13.0, 5.0, 1.0, true, true, true, true);
	glPopMatrix();
	// right part
	glPushMatrix();
		glTranslatef(-5.0, -4.5, 0.0);
		createHexahedron(3.0, 4.0, 1.0, true, false, true, true);
	glPopMatrix();
	// left part
	glPushMatrix();
		glTranslatef(5.0, -4.5, 0.0);
		createHexahedron(3.0, 4.0, 1.0, true, false, true, true);
	glPopMatrix();
	// right interior
	glPushMatrix();
		glTranslatef(-3.0, -3.5, 0.0);
		createHexahedron(1.0, 2.0, 1.0, true, false, true, false);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0, -3.0, 0.0);
		createHexahedron(1.0, 1.0, 1.0, true, false, true, false);
	glPopMatrix();
	// left interior
	glPushMatrix();
		glTranslatef(3.0, -3.5, 0.0);
		createHexahedron(1.0, 2.0, 1.0, true, false, false, false);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.0, -3.0, 0.0);
		createHexahedron(1.0, 1.0, 1.0, true, false, true, false);
	glPopMatrix();
 glPopMatrix();
};