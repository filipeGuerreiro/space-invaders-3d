#include "AlienBullet.h"

AlienBullet::AlienBullet() {
	AlienBullet::_a = NULL;
	_x = _y = _z = 0.0;
	_isAlive = false;
	_isDepleted = false;
	_radius = 1;
	diffuse[0] = 0.0;
	diffuse[1] = 1.0;
	diffuse[2] = 1.0;
	diffuse[3] = 1.0;
	ambient[0] = ambient[1] = ambient[2] = 0.1;
	ambient[3] = 1.0;
};

AlienBullet::AlienBullet(float px, float py, float pz) : Material(px, py, pz) {};

Alien *AlienBullet::getAlien() {
	return _a;
};

bool AlienBullet::isDepleted() {
	return _isDepleted;
};

void AlienBullet::depleted() {
	_isDepleted = true;
};

void AlienBullet::setAlien(Alien *a) { 
 	_a = a;
};

void AlienBullet::draw() {

 glPushMatrix();
	if(glIsEnabled(GL_LIGHTING)) {
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	} else
		glColor3f(0.0, 1.0, 1.0);
	glTranslatef(getX(), getY(), getZ());
	if(_debug)
		glutWireSphere(_radius, 10, 10);
	createHexahedron(1.0, 2.0, 1.0, true, true, true, true);
 glPopMatrix();

};

void AlienBullet::move() {
	if(getY() < LOWER_Y)
		_isAlive = false;
	else
		this->setCoordinates(getX(), getY()-BULLET_TRAVEL, getZ());
};

void AlienBullet::fire() {
	_isAlive = true;
	this->setCoordinates(_a->getX(), _a->getY()-2.5, _a->getZ());
	//PlaySound((LPCSTR) "C:\\Users\\Filipe\\Desktop\\Dropbox\\Project2\\sounds\\alien_laser.WAV", NULL, SND_FILENAME | SND_ASYNC);
};