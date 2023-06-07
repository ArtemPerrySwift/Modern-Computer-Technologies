#pragma once
#include "MagnetInfo.h"
#include "IntervalRef.h"
#include "Faces.h"

class MagnetElement : public MagnetInfo, public FaceXZ
{
public:
	MagnetElement(const IntervalRef& intervalX, const IntervalRef& intervalZ, double pX, double pZ);
};

