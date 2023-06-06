#pragma once
#include "AreaInfo.h"
#include "IntervalForSplit.h"

class MeshInfo
{
private:
	std::vector<double> _x;
	std::vector<double> _z;
	std::vector<IntervalForSplit> _intervalsXForSplit;
	std::vector<IntervalForSplit> _intervalsZForSplit;
	std::vector<AreaInfo> _areas;
	void checkBasePointsArr(std::vector<double>& p, std::string_view pName);

public:
	MeshInfo(libconfig::Config& config);
	MeshInfo(std::string& configFileName);
	MeshInfo(libconfig::Setting& setting);

};
