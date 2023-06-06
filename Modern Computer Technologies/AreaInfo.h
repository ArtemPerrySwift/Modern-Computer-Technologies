#pragma once
#include <array>
#include <sstream>
#include <libconfig.h>

typedef unsigned char BoundCount_t;

struct AreaInfo
{
public:
	int _intervalNumX;
	int _intervalNumY;

	AreaInfo() = default;

	AreaInfo(int _intervalNumX,
		int _intervalNumY);

	AreaInfo(std::istream& in);

	AreaInfo(libconfig::Setting& setting);

};

