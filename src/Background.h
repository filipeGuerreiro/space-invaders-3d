#pragma once
#include "Material.h"

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define W 50.0
#define H 50.0
#define D -3.0

#define N_QUAD 50.0

class Background : public Material {

public:
	Background();
	void draw();

private:
	GLuint _texture;
	GLuint loadTexture(const char * filename, int wrap, int width, int height);
};