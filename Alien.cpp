#include "Alien.h"

bool Alien::_animate = false;
bool Alien::_moveDown = false;
bool Alien::_moveRight = true;
bool Alien::_3D = false;

Alien::Alien(float px, float py, float pz) : Material(px, py, pz) {
	_radius = 3;
	_hasBullets = false;
	_explosion = new ParticlesManager();
};

bool Alien::equals(Alien *a) {
	return this->getX() == a->getX() && this->getY() == a->getY();
};

Alien *Alien::getAlien() {
	return this;
};

bool Alien::hasBullets() {
	return _hasBullets;
};

ParticlesManager* Alien::getExplosion() {
	return _explosion;
};

void Alien::setBullets(bool b) {
	_hasBullets = b;
};

void Alien::set3D(bool b) {
	_3D = b;
};

bool Alien::isGoingRight() {
	return _moveRight;
};

bool Alien::isGoingDown() {
	return _moveDown;
};

void Alien::changeAnimation() {
	_animate = !_animate;
};

void Alien::moveLeft() {
	this->setCoordinates(getX()-MOVE_X, getY(), getZ());
	if(this->getX() <= -X_MAX)
		_moveDown = true;
};

void Alien::moveRight() {
	this->setCoordinates(getX()+MOVE_X, getY(), getZ());
	if(this->getX() >= X_MAX)
		_moveDown = true;
};

void Alien::moveDown() {
	this->setCoordinates(getX(), getY()-MOVE_Y, getZ());
	_moveDown = false;
	_moveRight = !_moveRight;
};

void Alien::die() {
	_isAlive = false;
	_explosion->init(this);
};

void Alien::updateExplosion(int elapsed) {
	_explosion->update(this, elapsed);
	
	glPushMatrix();
		glTranslatef(getX(), getY(), getZ());
		_explosion->draw();
	glPopMatrix();
};

void Alien::fire() {};