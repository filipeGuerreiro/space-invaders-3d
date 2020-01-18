#pragma once

#include "Entity.h"

// Objecto que ira ser desenhado na cena

class Material : public Entity {

public:
	void setDebug();
	float getRaio();
	float getRed();
	float getGreen();
	float getBlue();

protected:
	Material();
	Material(float, float, float);

	// creates a simple hexahedron with front, back, side faces disabled if respective bool at false
	void createHexahedron(float w, float h, float d, bool f, bool b, bool r, bool l);

	// creates a rectangle with x, y side
	void createRectangle(float x, float y);

	/* propriedadades do material */
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat ambient[4];
	/* expoente especular */
	GLfloat shininess[1];

	// mostra as bounding spheres para deteccao de colisoes
	static bool _debug;
	// raio da bounding sphere
	float _radius;

private:
	// calcula o produto externo de v1 e v2 e guarda em n
	void crossProduct(float n[3], float v1[3], float v2[3]);
	// normaliza um vector
	void normalize(float n[3]);
};