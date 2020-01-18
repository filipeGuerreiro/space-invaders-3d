#include "Entity.h"

Entity::Entity() {};

Entity::Entity(float px, float py, float pz) {
	_x = px;
	_y = py;
	_z = pz;
	_isAlive = true;
};

float Entity::getX() { 
	return _x;
};

float Entity::getY() {
	return _y;
};

float Entity::getZ() {
	return _z;
};

float Entity::getScale() {
	return _scale;
};

void Entity::setScale(float s) {
	_scale = s;
};

bool Entity::isAlive() {
	return _isAlive;
};

void Entity::die() {
	_isAlive = false;
};

void Entity::reset() {
	_isAlive = true;
};

void Entity::setCoordinates(float px, float py, float pz) {
	_x = px;
	_y = py;
	_z = pz;
};