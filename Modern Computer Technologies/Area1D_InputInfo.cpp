#include "Area1D_InputInfo.h"


Area1D_InputInfo::Area1D_InputInfo(int intervalNum, BoundaryCondition& conditionForFirstIntervalPoint, BoundaryCondition& conditionForSecondIntervalPoint) : _conditionForLeftBoundary(conditionForFirstIntervalPoint), _conditionForRightBoundary(conditionForSecondIntervalPoint)
{
	setIntervalNum(intervalNum);
}

int Area1D_InputInfo::getIntervalNum() const
{
	return _intervalNum;
}

void Area1D_InputInfo::setIntervalNum(int intervalNum)
{
	if (intervalNum < 0)
		throw std::exception("Interval number cannot be less than 0");

	_intervalNum = intervalNum;
}

Area1D_InputInfo::Area1D_InputInfo(std::istream& in) : _conditionForLeftBoundary(in), _conditionForRightBoundary(in)
{
	int intervalNum;
	in >> intervalNum;
	if (in.fail())
		throw std::exception("Cannot read interval number");
	setIntervalNum(intervalNum);
}

Area1D_InputInfo::Area1D_InputInfo(libconfig::Setting& setting) : _conditionForLeftBoundary(getSubSetting(setting, "Interval1Condition")),
_conditionForRightBoundary(getSubSetting(setting, "Interval2Condition"))
{
	int intervalNum;
	setVarFromSetting(setting, intervalNum, "IntervalNum");
	setIntervalNum(intervalNum);
}
