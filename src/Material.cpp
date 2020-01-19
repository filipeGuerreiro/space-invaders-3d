#include "Material.h"

bool Material::_debug = false;

Material::Material() : Entity() {};

Material::Material(float px, float py, float pz) : Entity(px, py, pz) {

	diffuse[0] = diffuse[1] = diffuse[2] = 0.0;
	diffuse[3] = 1.0;
	
	ambient[0] = ambient[1] = ambient[2] = 0.0;
	ambient[3] = 1.0;

	specular[0] = specular[1] = specular[2] = 0.5;
	specular[3] = 1.0;
	shininess[0] = 0.0;
};

float Material::getRed() {
	return diffuse[0];
};

float Material::getGreen() {
	return diffuse[1];
};

float Material::getBlue() {
	return diffuse[2];
};

void Material::setDebug() {
	_debug = !_debug;
};

float Material::getRaio() {
	return _radius;
};

void Material::crossProduct(float n[3], float u[3], float v[3]) {
	n[0] = u[1] * v[2] - u[2] * v[1];
	n[1] = u[2] * v[0] - u[0] * v[2];
	n[2] = u[0] * v[1] - u[1] * v[0];
};

void Material::normalize(float n[3]) {
	float len;
	len = sqrt(pow(n[0], 2) + pow(n[1], 2) + pow(n[2], 2));
	if(len == 0.0)
		len = 1.0;
	n[0] /= len;
	n[1] /= len;
	n[2] /= len;
};

void Material::createRectangle(float x, float y) {

	glBegin(GL_POLYGON);
		glVertex3f(-x, -y, 0.0);
		glVertex3f(x, -y, 0.0);
		glVertex3f(x, y, 0.0);
		glVertex3f(-x, y, 0.0);
	glEnd();
};

void Material::createHexahedron(float w, float h, float d, bool f, bool b, bool r, bool l) {
	float x = w/2;
	float y = h/2;
	float z = d/2;
	/*float n[3] = {1.0, 1.0, 1.0}; 
	float v1[3] = {x, y, 0.0}; 
	float v2[3] = {x, y, 0.0};*/

	/* TOP */
	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(-x, -y, 0);
		glVertex3f(-x, y, 0);
		glVertex3f(x, y, 0);
		glVertex3f(x, -y, 0);
		/*v1[0] = -x; // -x y 0
		v2[1] = -y; // x -y 0
		crossProduct(n, v1, v2);
		normalize(n);*/
	glEnd();
	/* BOTTOM */
	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(-x, -y, -z);
		glVertex3f(-x, y, -z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, -z);
		/*v1[2] = -z; // -x y -z
		v2[2] = -z; // x -y -z
		crossProduct(n, v1, v2);
		normalize(n);
		glNormal3fv(n);*/
	glEnd();
	/* FRONT */
	if(f) {
		glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0.0, -1.0, 0.0);
			glVertex3f(-x, -y, 0);
			glVertex3f(-x, -y, -z);
			glVertex3f(x, -y, -z);
			glVertex3f(x, -y, 0);
			/*v1[1] = -y; // -x -y -z
			v2[2] = 0.0; // x -y 0
			crossProduct(n, v1, v2);
			normalize(n);
			glNormal3fv(n);*/
		glEnd();
	}
	/* BACK */
	if(b) {
		glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(-x, y, 0);
			glVertex3f(-x, y, -z);
			glVertex3f(x, y, -z);
			glVertex3f(x, y, 0);
			/*v1[1] = y; // -x y -z
			v2[1] = y; // x y 0
			crossProduct(n, v1, v2);
			normalize(n);
			glNormal3fv(n);*/
		glEnd();
	}
	/* RIGHT */
	if(r) {
		glBegin(GL_TRIANGLE_FAN);
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(x, -y, 0);
			glVertex3f(x, -y, -z);
			glVertex3f(x, y, -z);
			glVertex3f(x, y, 0);
			/*v1[0] = x; // x y -z
			crossProduct(n, v1, v2);
			normalize(n);
			glNormal3fv(n);*/
		glEnd();
	}
	/* LEFT */
	if(l) {
		glBegin(GL_TRIANGLE_FAN); 
			glNormal3f(-1.0, 0.0, 0.0);
			glVertex3f(-x, -y, 0);
			glVertex3f(-x, -y, -z);
			glVertex3f(-x, y, -z);
			glVertex3f(-x, y, 0);
			/*v1[0] = -x; // -x y -z
			v2[0] = -x; // -x y 0
			crossProduct(n, v1, v2);
			normalize(n);
			glNormal3fv(n);*/
		glEnd();
	}
};