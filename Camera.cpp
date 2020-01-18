#include "Camera.h"

float Camera::_w = INIT_WIDTH;
float Camera::_h = INIT_HEIGHT;

Camera::Camera() {};

Camera *Camera::getCamera() {
	return this;
};

float Camera::getWidth() {
	return _w;
};

float Camera::getHeight() {
	return _h;
};

float Camera::getVerticalPlane() {
	return VERTICAL;
};

float Camera::getHorizontalPlane() {
	return HORIZONTAL;
};

float Camera::getDepthPlane() {
	return DEPTH;
};

void Camera::setWidth(float w) {
	_w = w;
};

void Camera::setHeight(float h) {
	_h = h;
};

void Camera::draw() {

	glViewport(0, 0, _w, _h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	drawProjection();
};