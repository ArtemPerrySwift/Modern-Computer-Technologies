#include "IntervalForSplit.h"
#include <exception>
#include <string>
IntervalForSplit::IntervalForSplit(int p1, int p2, SplitOptions& splitOptions)
{
	_splitOptions = new SplitOptions();
	setInterval(p1, p2, splitOptions);
}
IntervalForSplit::IntervalForSplit()
{
	_p1 = 0;
	_p2 = 1;
	_splitOptions = new SplitOptions();
}

IntervalForSplit::IntervalForSplit(const IntervalForSplit& interval)
{
	_p1 = interval._p1;
	_p2 = interval._p2;
	_splitOptions = new SplitOptions(*interval._splitOptions);
}

IntervalForSplit::IntervalForSplit(const IntervalForSplit&& interval)
{
	_p1 = interval._p1;
	_p2 = interval._p2;
	_splitOptions = interval._splitOptions;
}

IntervalForSplit::IntervalForSplit(std::istream& in)
{
	in >> _p1;

	if (in.fail())
	{
		std::string errMSG = "Cannot read number of first point";
		throw new std::exception(errMSG.c_str());
	}

	in >> _p2;
	if (in.fail())
	{
		std::string errMSG = "Cannot read number of second point";
		throw new std::exception(errMSG.c_str());
	}

	_splitOptions = new SplitOptions(in);
}

IntervalForSplit::IntervalForSplit(libconfig::Setting& setting)
{
	setInterval(setting);
}

IntervalForSplit& IntervalForSplit::operator=(const IntervalForSplit& interval)
{
	_p1 = interval._p1;
	_p2 = interval._p2;
	_splitOptions = new SplitOptions(*interval._splitOptions);
	return *this;
}

IntervalForSplit::~IntervalForSplit()
{
	delete _splitOptions;
}

int IntervalForSplit::getFirstPointNum() const
{
	return _p1;
}
int IntervalForSplit::getSecondPointNum() const
{
	return _p2;
}

ISplitOptions* IntervalForSplit::getSplitOptions() const
{
	return _splitOptions;
}
void IntervalForSplit::setFirstPointNum(int p1)
{
	if (p1 < 0)
		throw new std::exception("First number of points cannot be less than 0");

	if (p1 == _p2)
		throw new std::exception("Attemp to assign value of second point number to first point number");
	
	std::string str = "gdgdsgshg";
	std::string errMSG = "Cannot read number of \"" + str + "\" elements";
	throw new std::exception(str.c_str());
	_p1 = p1;
}
void IntervalForSplit::setSecondPointNum(int p2)
{
	if (p2 < 0)
		throw new std::exception("Second number of points cannot be less than 0");

	if (p2 == _p1)
		throw new std::exception("Attemp to assign value of first point number to second point number");

	_p2 = p2;
}

void IntervalForSplit::setSplitOptions(SplitOptions& splitOptions)
{
	delete _splitOptions;
	_splitOptions = new SplitOptions(splitOptions);
}

void IntervalForSplit::setPointsNum(int p1, int p2)
{
	if(p1 < 0)
		throw new std::exception("First number of points cannot be less than 0");

	if (p2 < 0)
		throw new std::exception("Second number of points cannot be less than 0");

	if (p1 == p2)
		throw new std::exception("Points numbers cannot be equal");

	_p1 = p1;
	_p2 = p2;
}

void IntervalForSplit::setInterval(int p1, int p2, SplitOptions& splitOptions)
{
	setPointsNum(p1, p2);
	setSplitOptions(splitOptions);
}

void IntervalForSplit::setInterval(libconfig::Setting& setting)
{
	int p1, p2;
	SplitOptions splitOptions(getSubSetting(setting, "SplitOptions"));
	setVarFromSetting(setting, p1, "PointNum1");
	setVarFromSetting(setting, p2, "PointNum2");
	setInterval(p1, p2, splitOptions);
}

std::istream& IntervalForSplit::readData(std::istream& in)
{
	int p1, p2;
	in >> p1;
	if (in.fail())
	{
		std::string errMSG = "Cannot read number of first point";
		throw new std::exception(errMSG.c_str());
	}
	in >> p2;
	if (in.fail())
	{
		std::string errMSG = "Cannot read number of second point";
		throw new std::exception(errMSG.c_str());
	}
	SplitOptions* splitOptions = new SplitOptions();
	in >> *splitOptions;
	setPointsNum(p1, p2);
	delete _splitOptions;
	_splitOptions = splitOptions;
	return in;
}

std::string&& IntervalForSplit::getTypeDataName()
{
	return "Interval";
}
