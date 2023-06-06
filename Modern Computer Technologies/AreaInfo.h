#pragma once
#include <array>
#include <sstream>
#include "LibconfigDeluxe.h"

typedef unsigned char BoundCount_t;

struct AreaInfo
{
public:
	int _intervalNumX;
	int _intervalNumZ;
	double _pX;
	double _pZ;
	AreaInfo() = default;

	AreaInfo(const int _intervalNumX, const int _intervalNumZ, const double pX, const double pZ);

	AreaInfo(std::istream& in);

	AreaInfo(libconfig::Setting& setting);

};

