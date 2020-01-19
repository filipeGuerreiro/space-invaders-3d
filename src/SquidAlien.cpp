#include "SquidAlien.h"

SquidAlien::SquidAlien(float px, float py, float pz) : Alien(px, py, pz) { 
	diffuse[0] = 0.983;
	diffuse[1] = 0.132;
	diffuse[2] = 0.362;
	diffuse[3] = 1.0;
	ambient[0] = 0.0983;
	ambient[1] = 0.0132;
	ambient[2] = 0.0362;
	ambient[3] = 1.0;
};

void SquidAlien::draw() {

	if(glIsEnabled(GL_LIGHTING)) {
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	} else
		glColor3f(0.983, 0.132, 0.362);

	glPushMatrix();
		glTranslatef(getX(), getY(), getZ());
		_explosion->draw();
	glPopMatrix();

	if(_animate) {
		this->firstAnimation();
	} else {
		this->secondAnimation();
	}
}

void SquidAlien::firstAnimation() {
	glPushMatrix();
		glTranslatef(getX(), getY(), getZ());
		if(_3D)
			glRotatef(90.0, 1.0, 0.0, 0.0);
		if(_debug)
				glutWireSphere(_radius, 10, 10);
		glScalef(0.55, 0.55, 2.5);
		/* Base da cabeça */
		glPushMatrix();
			createHexahedron(6.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Nariz */
		glPushMatrix();
			glTranslatef(0.0, 1.0, 0.0);
			createHexahedron(2.0, 1.0, 1.0, false, false, true, true);
		glPopMatrix();
		/* Tempora esquerda */
		glPushMatrix();
			glTranslatef(3.0, 1.0, 0.0);
			createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Tempora direita */
		glPushMatrix();
			glTranslatef(-3.0, 1.0, 0.0);
			createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Sobrolho */
		glPushMatrix();
			glTranslatef(0.0, 2.0, 0.0);
			createHexahedron(6.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Testa */
		glPushMatrix();
			glTranslatef(0.0, 3.0, 0.0);
			createHexahedron(4.0, 1.0, 1.0, false, true, true, true);
		glPopMatrix();
		/* Escalpo */
		glPushMatrix();
			glTranslatef(0.0, 4.0, 0.0);
			createHexahedron(2.0, 1.0, 1.0, false, true, true, true);
		glPopMatrix();
		/* Elo dos tentaculos */
		glPushMatrix();
			glTranslatef(0.0, -2.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Tentaculo esquerdo */
		glPushMatrix();
			glTranslatef(1.0, -1.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, false, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.0, -3.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(2.0, -2.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(3.0, -3.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Tentaculo direito */
		glPushMatrix();
			glTranslatef(-1.0, -1.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, false, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-1.0, -3.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.0, -2.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-3.0, -3.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

 glPopMatrix();
}

void SquidAlien::secondAnimation() {
	glPushMatrix();
		glTranslatef(getX(), getY(), getZ());
		if(_3D)
			glRotatef(90.0, 1.0, 0.0, 0.0);
		if(_debug)
			glutWireSphere(_radius, 10, 10);
		glScalef(0.55, 0.55, 2.5);
		/* Base da cabeça */
		glPushMatrix();
			createHexahedron(6.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Nariz */
		glPushMatrix();
			glTranslatef(0.0, 1.0, 0.0);
			createHexahedron(2.0, 1.0, 1.0, false, false, true, true);
		glPopMatrix();
		/* Tempora esquerda */
		glPushMatrix();
			glTranslatef(3.0, 1.0, 0.0);
			createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Tempora direita */
		glPushMatrix();
			glTranslatef(-3.0, 1.0, 0.0);
			createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Sobrolho */
		glPushMatrix();
			glTranslatef(0.0, 2.0, 0.0);
			createHexahedron(6.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();
		/* Testa */
		glPushMatrix();
			glTranslatef(0.0, 3.0, 0.0);
			createHexahedron(4.0, 1.0, 1.0, false, true, true, true);
		glPopMatrix();
		/* Escalpo */
		glPushMatrix();
			glTranslatef(0.0, 4.0, 0.0);
			createHexahedron(2.0, 1.0, 1.0, false, true, true, true);
		glPopMatrix();
		/* Tentaculo esquerdo */
		glPushMatrix();
			glTranslatef(2.0, -1.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, false, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(2.0, -3.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(3.0, -2.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(2.0, -3.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

		/* Tentaculo direito */
		glPushMatrix();
			glTranslatef(-2.0, -1.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, false, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.0, -3.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-3.0, -2.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.0, -3.0, 0.0);
			createHexahedron(1.0, 1.0, 1.0, true, true, true, true);
		glPopMatrix();

 glPopMatrix();
}