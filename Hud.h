#pragma once

#include <fstream>
#include <iostream>

#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <windows.h>
	#include "glut/include/GL/glut.h"
#endif

#include "CameraOrtogonal.h"

using namespace std;

#define SCORE 0
#define LIVES 1

class Hud {

public:
	Hud();
	Hud *getHud();
	int getLives();
	int getScore();
	void reset();
	void addScore(int);
	void takeLife();
	void message(std::string, void*, int, int);
	void draw(float, float);
	void youWin(float, float);
	void youLose(float, float);

private:
	//static Hud *_HUD;
	int _lives;
	int _score;
	char _text[256];
	//GLuint _textures[2];
	GLuint loadTexture(const char * filename, int wrap, int width, int height);
};