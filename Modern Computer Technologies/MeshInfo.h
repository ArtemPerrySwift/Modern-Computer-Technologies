#pragma once
#include "AreaInfo.h"
#include "IntervalForSplit.h"
#include "SplittedInterval.h"
#include "MagnetElement.h"

class MeshInfo
{
	std::vector<SplittedInterval> _intervalsX;
	std::vector<SplittedInterval> _intervalsZ;
	std::vector<Area> _areas;

	double _I;
	void checkBasePointsArr(std::vector<double>& p, std::string_view pName);
	void splitIntervals(std::vector<SplittedInterval>& splittedIntervals, const std::vector<IntervalForSplit>& intervalsForSplit, const std::vector<double>& points);
	
public:
	MeshInfo(libconfig::Config& config);
	MeshInfo(std::string& configFileName);
	MeshInfo(libconfig::Setting& setting);
	MeshInfo(const std::vector<double> _x, const std::vector<double> _z, const std::vector<IntervalForSplit> _intervalsXForSplit, const std::vector<IntervalForSplit> _intervalsZForSplit, double I, const std::vector<AreaInfo> _areas);

	const std::vector<SplittedInterval>& getIntervalsX() const;
	const std::vector<SplittedInterval>& getIntervalsZ() const;
	void getMagneticElements(std::vector<MagnetElement>& _magneticElements) const;
	double getI() const;
	void setI(double I);
};

