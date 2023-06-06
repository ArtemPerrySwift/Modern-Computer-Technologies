#pragma once
#include "Area1D_info.h"
class Area1D_InputInfo : public Area1D_info
{
private:
	int _intervalNum;
public:
	void setIntervalNum(int intervalNum);
	Area1D_InputInfo(int _intervalNum, BoundaryCondition& conditionForFirstIntervalPoint, BoundaryCondition& conditionForSecondIntervalPoint);
	Area1D_InputInfo() = default;
	Area1D_InputInfo(std::istream& in);
	Area1D_InputInfo(libconfig::Setting& setting);
	int getIntervalNum() const;

};

