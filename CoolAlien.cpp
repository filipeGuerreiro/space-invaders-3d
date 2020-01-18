#include "CoolAlien.h"

CoolAlien::CoolAlien(float px, float py, float pz) : Alien(px, py, pz) {
	diffuse[0] = 1.0;
	diffuse[1] = 0.45;
	diffuse[2] = 0.0;
	diffuse[3] = 1.0;
	ambient[0] = 0.1;
	ambient[1] = 0.045;
	ambient[2] = 0.0;
	ambient[3] = 1.0;
};

void CoolAlien::draw() {

	if(glIsEnabled(GL_LIGHTING)) {
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	} else
		glColor3f(1.0, 0.45, 0.0);
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

void CoolAlien::firstAnimation() {

		glPushMatrix();
			glTranslatef(getX(), getY(), getZ());
			if(_3D)
				glRotatef(90.0, 1.0, 0.0, 0.0);
			if(_debug)
				glutWireSphere(_radius, 10, 10);
			glScalef(6, 6, 25);
			/* Bigode */
			glPushMatrix();
				createHexahedron(.8, .1, .1, true, true, false, false);
			glPopMatrix();
			/* Nariz */
			glPushMatrix();
				glTranslatef(0.0, 0.1, 0.0);
				createHexahedron(0.2, 0.1, 0.1, false, false, true, true);
			glPopMatrix();
			/* Sobrolho */
			glPushMatrix();
				glTranslatef(0.0, 0.2, 0.0);
				createHexahedron(0.6, 0.1, 0.1, true, true, true, true);
			glPopMatrix();
			/* Boca de cima */
			glPushMatrix();
				glTranslatef(0.0, -0.1, 0.0);
				createHexahedron(0.6, 0.1, 0.1, true, false, true, true);
			glPopMatrix();
			/* Patilha da esquerda */
			glPushMatrix();
				glTranslatef(0.3, 0.1, 0.0);
				createHexahedron(0.2, 0.1, 0.1, false, true, true, true);
			glPopMatrix();
			/* Patilha da direita */
			glPushMatrix();
				glTranslatef(-0.3, 0.1, 0.0);
				createHexahedron(0.2, 0.1, 0.1, false, true, true, true);
			glPopMatrix();
			/* Parte inferior da antena da esquerda */
			glPushMatrix();
				glTranslatef(0.15, 0.3, 0);
				createHexahedron(0.1, 0.1, 0.1, false, true, true, true);
			glPopMatrix();
			/* Parte inferior da antena da direita */
			glPushMatrix();
				glTranslatef(-0.15, 0.3, 0);
				createHexahedron(0.1, 0.1, 0.1, false, true, true, true);
			glPopMatrix();
			/* Parte superior da antena da esquerda */
			glPushMatrix();
				glTranslatef(0.25, 0.4, 0);
				createHexahedron(0.1, 0.1, 0.1, true, true, true, true);
			glPopMatrix();
			/* Parte superior da antena da direita */
			glPushMatrix();
				glTranslatef(-0.25, 0.4, 0);
				createHexahedron(0.1, 0.1, 0.1, true, true, true, true);
			glPopMatrix();
			/* Braco esquerdo */
			glPushMatrix();
				glTranslatef(0.45, -0.1, 0);
				createHexahedron(0.1, 0.3, 0.1, true, true, true, true);
			glPopMatrix();
			/* Braco direito */
			glPushMatrix();
				glTranslatef(-0.45, -0.1, 0);
				createHexahedron(0.1, 0.3, 0.1, true, true, true, true);
			glPopMatrix();
			/* Maxilar esquerdo */
			glPushMatrix();
				glTranslatef(0.25, -0.2, 0);
				createHexahedron(0.1, 0.1, 0.1, true, false, true, true);
			glPopMatrix();
			/* Maxilar direito */
			glPushMatrix();
				glTranslatef(-0.25, -0.2, 0);
				createHexahedron(0.1, 0.1, 0.1, true, false, true, true);
			glPopMatrix();
			/* Mandibula esquerda */
			glPushMatrix();
				glTranslatef(0.15, -0.3, 0);
				createHexahedron(0.125, 0.1, 0.1, true, true, true, true);
			glPopMatrix();
			/* Mandibula direita */
			glPushMatrix();
				glTranslatef(-0.15, -0.3, 0);
				createHexahedron(0.125, 0.1, 0.1, true, true, true, true);
			glPopMatrix();
		glPopMatrix();
}

void CoolAlien::secondAnimation() {

	glPushMatrix();
		glTranslatef(getX(), getY(), getZ());
		if(_3D)
			glRotatef(90.0, 1.0, 0.0, 0.0);
		if(_debug)
			glutWireSphere(_radius, 10, 10);
		glScalef(6, 6, 25);
		/* Bigode */
		glPushMatrix();
			createHexahedron(0.8, 0.1, 0.1, true, true, false, false);
		glPopMatrix();
		/* Nariz */
		glPushMatrix();
			glTranslatef(0.0, 0.1, 0.0);
			createHexahedron(0.2, 0.1, 0.1, false, false, true, true);
		glPopMatrix();
		/* Sobrolho */
		glPushMatrix();
			glTranslatef(0.0, 0.2, 0.0);
			createHexahedron(0.6, 0.1, 0.1, true, true, true, true);
		glPopMatrix();
		/* Boca de cima */
		glPushMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			createHexahedron(0.6, 0.1, 0.1, true, false, true, true);
		glPopMatrix();
		/* Patilha da esquerda */
		glPushMatrix();
			glTranslatef(0.3, 0.1, 0.0);
			createHexahedron(0.2, 0.1, 0.1, false, true, true, true);
		glPopMatrix();
		/* Patilha da direita */
		glPushMatrix();
			glTranslatef(-0.3, 0.1, 0.0);
			createHexahedron(0.2, 0.1, 0.1, false, true, true, true);
		glPopMatrix();
		/* Parte inferior da antena da esquerda */
		glPushMatrix();
			glTranslatef(0.15, 0.3, 0);
			createHexahedron(0.1, 0.1, 0.1, false, true, true, true);
		glPopMatrix();
		/* Parte inferior da antena da direita */
		glPushMatrix();
			glTranslatef(-0.15, 0.3, 0);
			createHexahedron(0.1, 0.1, 0.1, false, true, true, true);
		glPopMatrix();
		/* Parte superior da antena da esquerda */
		glPushMatrix();
			glTranslatef(0.25, 0.4, 0);
			createHexahedron(0.1, 0.1, 0.1, true, true, true, true);
		glPopMatrix();
		/* Parte superior da antena da direita */
		glPushMatrix();
			glTranslatef(-0.25, 0.4, 0);
			createHexahedron(0.1, 0.1, 0.1, true, true, true, true);
		glPopMatrix();
		/* Braco esquerdo */
		glPushMatrix();
			glTranslatef(0.45, 0.2, 0);
			createHexahedron(0.1, 0.3, 0.1, true, true, true, true);
		glPopMatrix();
		/* Braco direito */
		glPushMatrix();
			glTranslatef(-0.45, 0.2, 0);
			createHexahedron(0.1, 0.3, 0.1, true, true, true, true);
		glPopMatrix();
		/* Maxilar esquerdo */
		glPushMatrix();
			glTranslatef(0.25, -0.2, 0);
			createHexahedron(0.1, 0.1, 0.1, true, false, true, true);
		glPopMatrix();
		/* Maxilar direito */
		glPushMatrix();
			glTranslatef(-0.25, -0.2, 0);
			createHexahedron(0.1, 0.1, 0.1, true, false, true, true);
		glPopMatrix();
		/* Mandibula esquerda */
		glPushMatrix();
			glTranslatef(0.30, -0.3, 0);
			createHexahedron(0.125, 0.1, 0.1, true, true, true, true);
		glPopMatrix();
		/* Mandibula direita */
		glPushMatrix();
			glTranslatef(-0.30, -0.3, 0);
			createHexahedron(0.125, 0.1, 0.1, true, true, true, true);
		glPopMatrix();
	glPopMatrix();
}