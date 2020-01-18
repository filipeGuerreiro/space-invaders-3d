#include "SkullAlien.h"

SkullAlien::SkullAlien(float px, float py, float pz) : Alien(px, py, pz) { 
	diffuse[0] = 0.124;
	diffuse[1] = 0.4;
	diffuse[2] = 1.0;
	diffuse[3] = 1.0;
	ambient[0] = 0.0124;
	ambient[1] = 0.04;
	ambient[2] = 0.1;
	ambient[3] = 1.0;
};

void SkullAlien::draw() {
	if(glIsEnabled(GL_LIGHTING)) {
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	} else
		glColor3f(0.124, 0.4, 1.0);

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

void SkullAlien::firstAnimation() {
		
		glPushMatrix();
			glTranslatef(getX(), getY(), getZ());
			if(_3D)
				glRotatef(90.0, 1.0, 0.0, 0.0);
			if(_debug)
				glutWireSphere(_radius, 10, 10);
			glScalef(0.5, 0.5, 2.5);
			/* Base da cabeca */
			glPushMatrix();
				createHexahedron(11.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Nariz */
			glPushMatrix();
				glTranslatef(0.0, 1.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, false, false, true, true);
			glPopMatrix();
			/* Testa de baixo */
			glPushMatrix();
				glTranslatef(0.0, 2.0, 0.0);
				createHexahedron(11.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Patilha da esquerda */
			glPushMatrix();
				glTranslatef(4.25, 1.0, 0.0);
				createHexahedron(2.5, 1.0, 1.0, false, false, true, true);
			glPopMatrix();
			/* Patilha da direita */
			glPushMatrix();
				glTranslatef(-4.25, 1.0, 0.0);
				createHexahedron(2.5, 1.0, 1.0, false, false, true, true);
			glPopMatrix();
			/* Testa do meio */
			glPushMatrix();
				glTranslatef(0.0, 3.0, 0.0);
				createHexahedron(9.0, 1.0, 1.0, false, true, true, true);
			glPopMatrix();
			/* Testa de cima */
			glPushMatrix();
				glTranslatef(0.0, 4.0, 0.0);
				createHexahedron(4.0, 1.0, 1.0, false, true, true, true);
			glPopMatrix();
			/* Base do tentaculo da esquerda */
			glPushMatrix();
				glTranslatef(2.0, -1.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, false, true, true);
			glPopMatrix();
			/* Base do tentaculo da direita */
			glPushMatrix();
				glTranslatef(-2.0, -1.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, false, true, true);
			glPopMatrix();
			/* Elo dos tentaculos */
			glPushMatrix();
				glTranslatef(0.0, -2.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Parte do meio do tentaculo da esquerda */
			glPushMatrix();
				glTranslatef(3.0, -2.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Parte do meio do tentaculo da direita */
			glPushMatrix();
				glTranslatef(-3.0, -2.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Ponta do tentaculo da esquerda */
			glPushMatrix();
				glTranslatef(5.0, -3.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Ponta do tentaculo da direita */
			glPushMatrix();
				glTranslatef(-5.0, -3.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
		glPopMatrix();
}

void SkullAlien::secondAnimation() {

		glPushMatrix();
			glTranslatef(getX(), getY(), getZ());
			if(_3D)
				glRotatef(90.0, 1.0, 0.0, 0.0);
			if(_debug)
				glutWireSphere(_radius, 10, 10);
			glScalef(0.5, 0.5, 2.5);
			/* Base da cabeca */
			glPushMatrix();
				createHexahedron(11.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Nariz */
			glPushMatrix();
				glTranslatef(0.0, 1.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, false, false, true, true);
			glPopMatrix();
			/* Testa de baixo */
			glPushMatrix();
				glTranslatef(0.0, 2.0, 0.0);
				createHexahedron(11.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Patilha da esquerda */
			glPushMatrix();
				glTranslatef(4.25, 1.0, 0.0);
				createHexahedron(2.5, 1.0, 1.0, false, true, true, true);
			glPopMatrix();
			/* Patilha da direita */
			glPushMatrix();
				glTranslatef(-4.25, 1.0, 0.0);
				createHexahedron(2.5, 1.0, 1.0, false, true, true, true);
			glPopMatrix();
			/* Testa do meio */
			glPushMatrix();
				glTranslatef(0.0, 3.0, 0.0);
				createHexahedron(9.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Testa de cima */
			glPushMatrix();
				glTranslatef(0.0, 4.0, 0.0);
				createHexahedron(4.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Base do tentaculo da esquerda */
			glPushMatrix();
				glTranslatef(2.0, -1.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, false, true, true);
			glPopMatrix();
			/* Base do tentaculo da direita */
			glPushMatrix();
				glTranslatef(-2.0, -1.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, false, true, true);
			glPopMatrix();
			/* Elo dos tentaculos */
			glPushMatrix();
				glTranslatef(0.0, -2.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Parte do meio do tentaculo da esquerda */
			glPushMatrix();
				glTranslatef(3.0, -2.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Parte do meio do tentaculo da direita */
			glPushMatrix();
				glTranslatef(-3.0, -2.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Ponta do tentaculo da esquerda */
			glPushMatrix();
				glTranslatef(2.5, -3.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
			/* Ponta do tentaculo da direita */
			glPushMatrix();
				glTranslatef(-2.5, -3.0, 0.0);
				createHexahedron(2.0, 1.0, 1.0, true, true, true, true);
			glPopMatrix();
		glPopMatrix();
}