#pragma once
#include "Camera.h"
#include "Ship.h"

#define RATIO _w/_h
#define FOVY 45
#define Z_NEAR 1
#define Z_FAR 100

class CameraPerspective : public Camera {

public:
	CameraPerspective();
	void drawProjection();
	virtual void view() = 0;
};