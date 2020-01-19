#pragma once
#include "Entity.h"
#include "Ship.h"

/* WINDOW */
#define INIT_WIDTH 50
#define INIT_HEIGHT 50

/* PROJECTION */
#define VERTICAL 50.0
#define HORIZONTAL 50.0
#define DEPTH 50.0

class Camera : public Entity { 

public:
	Camera();
	Camera *getCamera();
	float getWidth();
	float getHeight();
	float getVerticalPlane();
	float getHorizontalPlane();
	float getDepthPlane();
	static void setWidth(float);
	static void setHeight(float);
	/* template method */
	void draw();
	virtual void drawProjection() = 0;

protected:
	/* tamanho da janela */
	static float _w, _h;
};