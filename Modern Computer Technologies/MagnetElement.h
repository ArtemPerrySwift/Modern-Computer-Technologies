#pragma once
#include "MagnetInfo.h"
#include "IntervalRef.h"

class MagnetElement : public MagnetInfo
{
	const IntervalRef& intervalX;
	const IntervalRef& intervalY;
};

