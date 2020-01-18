#include "Ship.h"

Ship *Ship::_ship = new Ship(N_INIT_X, N_INIT_Y, N_INIT_Z);

Ship::Ship(float px, float py, float pz) : Material(px, py, pz) {
	_explosion = new ParticlesManager();
	_radius = 4;

	diffuse[0] = diffuse[1] = diffuse[2] = diffuse[3] = 1.0;
	ambient[0] = ambient[1] = ambient[2] = 0.1;
	ambient[3] = 1.0;

	specular[0] = specular[1] = specular[2] = specular[3] = 1.0;
	shininess[0] = 50.0;
};

Ship* Ship::getShip() {
	return _ship;
}

ParticlesManager* Ship::getExplosion() {
	return _explosion;
};

void Ship::moveLeft() {
	if(this->getX() > LEFT_WALL)
		this->setCoordinates(getX()-MOVE_DIST, getY(), getZ());
};

void Ship::moveRight() {
	if(this->getX() < RIGHT_WALL)
		this->setCoordinates(getX()+MOVE_DIST, getY(), getZ());
};

void Ship::die() {
	_explosion->init(this);
};

void Ship::updateExplosion(int elapsed) {
	_explosion->update(this, elapsed);

	glPushMatrix();
		glTranslatef(getX(), getY(), getZ());
		_explosion->draw();
	glPopMatrix();
};

void Ship::drawExplosion() {
	_explosion->draw();
};

void Ship::draw() {
 glPushMatrix();
	if(glIsEnabled(GL_LIGHTING)) {
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	} else {
		glColor3f(1.0, 1.0, 1.0);
	}

	glTranslatef(getX(), getY(), getZ());
	
	if(_debug)
		glutWireSphere(_radius, 10, 10);
	glScalef(0.8, 0.8, 1.5);
	// Ponta do canhao 
	glPushMatrix();
		glTranslatef(0.0, 4.5, 0.0);
		createHexahedron(1.0, 1.0, 1.0, true, false, true, true);
	glPopMatrix();
	// Corpo do canhao 
	glPushMatrix();
		glTranslatef(0.0, 3.5, 0.0);
		createHexahedron(3.0, 1.0, 1.0, true, false, true, true);
	glPopMatrix();
	// Base do canhao 
	glPushMatrix();
		glTranslatef(0.0, 2.5, 0.0);
		createHexahedron(9.0, 1.0, 1.0, true, false, true, true);
	glPopMatrix();
	// Corpo 
	glPushMatrix();
		createHexahedron(11.0, 4.0, 1.0, true, true, true, true);
	glPopMatrix();
	
 glPopMatrix();
};

