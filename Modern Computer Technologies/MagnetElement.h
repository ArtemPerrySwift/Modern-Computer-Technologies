#pragma once
#include "MagnetInfo.h"
#include "IntervalRef.h"

class MagnetElement : public MagnetInfo
{
public:
	const IntervalRef& _intervalX;
	const IntervalRef& _intervalZ;
	MagnetElement(const IntervalRef& intervalX, const IntervalRef& intervalZ, double pX, double pZ);
};

