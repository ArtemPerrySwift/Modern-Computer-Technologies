#pragma once
#include "AreaInfo.h"

class MeshInfo
{
private:
	std::vector<double> _x;
	std::vector<double> _y;
	std::vector<IntervalForSplit> _intervalsXForSplit;
	std::vector<IntervalForSplit> _intervalsYForSplit;
	std::vector<AreaInfo> _areas;
	void checkBasePointsArr(std::vector<double>& p, std::string_view pName);

public:
	MeshInfo(libconfig::Config& config);
	MeshInfo(std::string& configFileName);
	MeshInfo(libconfig::Setting& setting);

};

