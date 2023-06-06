#include "MagnetInfo.h"
#include <exception>

MagnetInfo::MagnetInfo(double pX, double pZ)
{
	set_pX(pX);
	set_pZ(pZ);
}

MagnetInfo::MagnetInfo() = default;

void MagnetInfo::set_pX(double pX)
{
	if (pX < 0)
		throw std::exception("X Magnetization  cannot be less than 0");

	_pX = pX;
}

void MagnetInfo::set_pZ(double pZ)
{
	if (pZ < 0)
		throw std::exception("X Magnetization  cannot be less than 0");

	_pZ = pZ;
}

int MagnetInfo::get_pX() const
{
	return _pX;
}
int MagnetInfo::get_pZ() const
{
	return _pZ;
}
