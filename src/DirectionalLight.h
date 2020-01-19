#pragma once

#include "LightSource.h"

class DirectionalLight : public LightSource {
	
public:
	DirectionalLight(float, float, float);
	void draw();
};