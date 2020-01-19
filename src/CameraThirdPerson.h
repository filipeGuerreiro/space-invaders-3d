#pragma once
#include "CameraPerspective.h"

#define THIRD_Y -60.0
#define THIRD_Z 10.0

class CameraThirdPerson : public CameraPerspective {

public:
	CameraThirdPerson();
	void view();
};