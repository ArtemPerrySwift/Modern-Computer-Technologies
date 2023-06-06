#include "AreaInfo.h"

AreaInfo::AreaInfo(const int intervalNumX, const int intervalNumZ, const double pX, const double pZ) : _intervalNumX(intervalNumX), _intervalNumZ(intervalNumZ), _pX(pX), _pZ(pZ) {}

AreaInfo::AreaInfo(std::istream& in)
{
	in >> _intervalNumX;
	if (in.fail())
		throw std::exception("Cannot read interval number for X axes");
	in >> _intervalNumZ;
	if (in.fail())
		throw std::exception("Cannot read interval number for Z axes");
	in >> _pX;
	if (in.fail())
		throw std::exception("Cannot read pX value");
	in >> _pZ;
	if (in.fail())
		throw std::exception("Cannot read pZ value");

}


AreaInfo::AreaInfo(libconfig::Setting& setting)
{
	setVarFromSetting(setting, _intervalNumX, "IntervalXNum");
	setVarFromSetting(setting, _intervalNumZ, "IntervalZNum");
	setVarFromSetting(setting, _pX, "pX");
	setVarFromSetting(setting, _pZ, "pZ");
}


void AreaInfo::setIntervalNumX(int intervalNumX)
{
	if (intervalNumX < 0)
		throw std::exception("Interval X number for Area cannot be less than 0");

	_intervalNumX = intervalNumX;

}

void AreaInfo::setIntervalNumZ(int intervalNumZ)
{
	if (intervalNumZ < 0)
		throw std::exception("Interval Y number for Area cannot be less than 0");

	_intervalNumZ = intervalNumZ;
}

void AreaInfo::set_pX(double pX)
{
	if (pX < 0)
		throw std::exception("X Magnetization for Area cannot be less than 0");

	_pX = pX;
}

void AreaInfo::set_pZ(double pZ)
{
	if (pZ < 0)
		throw std::exception("X Magnetization for Area cannot be less than 0");

	_pZ = pZ;
}

int AreaInfo::getIntervalNumX() const
{
	return _intervalNumX;
}
int AreaInfo::getIntervalNumZ() const
{
	return _intervalNumZ;
}
int AreaInfo::get_pX() const
{
	return _pX;
}
int AreaInfo::get_pZ() const
{
	return _pZ;
}
