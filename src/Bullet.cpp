#include "Bullet.h"

Bullet::Bullet() {
	Bullet::_n = Ship::getShip();
	_x = _y = _z = 0.0;
	_isAlive = false;
	_radius = 1;
	diffuse[0] = diffuse[1] = diffuse[2] = diffuse[3] = 1.0;
	ambient[0] = ambient[1] = ambient[2] = 0.1;
	ambient[3] = 1.0;
};

Bullet::Bullet(float px, float py, float pz) : Material(px, py, pz) {};

void Bullet::draw() {

 glPushMatrix();
	if(glIsEnabled(GL_LIGHTING)) {
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	} else
		glColor3f(1.0, 1.0, 1.0);
	glTranslatef(getX(), getY(), getZ());
	if(_debug)
		glutWireSphere(_radius, 10, 10);
	createHexahedron(1.0, 2.0, 1.0, true, true, true, true);
 glPopMatrix();

};

void Bullet::move() {
	if(getY() > UPPER_Y)
		_isAlive = false;
	else
		this->setCoordinates(getX(), getY()+BULLET_TRAVEL, getZ());
};

void Bullet::fire() {
	_isAlive = true;
	this->setCoordinates(_n->getX(), _n->getY()+2.5, _n->getZ());
	PlaySound((LPCSTR) "C:\\Users\\Filipe\\Desktop\\Dropbox\\Project2\\sounds\\laser_fire.WAV", NULL, SND_FILENAME | SND_ASYNC);
};