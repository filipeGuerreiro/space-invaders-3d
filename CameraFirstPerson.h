#pragma once
#include "CameraPerspective.h"

#define FIRST_Y -43.5
#define FIRST_Z 4

class CameraFirstPerson : public CameraPerspective {

public:
	CameraFirstPerson();
	void view();
};