#include "MeshInfo.h"
#include "Area.h"
#include <algorithm>

libconfig::Config& prepareConfig(libconfig::Config& config)
{
	config.setAutoConvert(true);
	return config;
}

MeshInfo::MeshInfo(libconfig::Config& config) : MeshInfo(getSettingFromConfig(prepareConfig(config), "Mesh")) {}


MeshInfo::MeshInfo(std::string& configFileName) : MeshInfo(getConfigFromFile(configFileName)) {}


void MeshInfo::checkBasePointsArr(std::vector<double>& p, std::string_view pName)
{
	if (!std::is_sorted(p.begin(), p.end()))
	{
		std::string exeptionMSG = "Array for ";
		exeptionMSG.append(pName.data());
		exeptionMSG += " base point should be sorted";
		throw std::exception(exeptionMSG.c_str());
	}
		
	if (std::adjacent_find(p.begin(), p.end()) != p.end())
	{
		std::string exeptionMSG = "Array for ";
		exeptionMSG.append(pName.data());
		exeptionMSG += " base point should not contain dublicates";
		throw std::exception(exeptionMSG.c_str());
	}
}

MeshInfo::MeshInfo(libconfig::Setting& setting)
{
	std::vector<double> _x;
	std::vector<double> _z;
	std::vector<IntervalForSplit> _intervalsXForSplit;
	std::vector<IntervalForSplit> _intervalsZForSplit;
	std::vector<AreaInfo> areasInfo;

	libconfig::Setting& basePointsSetting = getSubSetting(setting, "BasePoints");
	setArrayFromConfigArray(basePointsSetting, _x, "X");
	checkBasePointsArr(_x, "X");
	setArrayFromConfigArray(basePointsSetting, _z, "Z");
	checkBasePointsArr(_z, "Z");
	libconfig::Setting& intervalSetting = getSubSetting(setting, "Intervals");
	setArrayFromConfigList(intervalSetting, _intervalsXForSplit, "X");
	setArrayFromConfigList(intervalSetting, _intervalsZForSplit, "Z");
	setArrayFromConfigList(setting, areasInfo, "Areas");

	for (const AreaInfo& areaInfo : areasInfo)
		_areas.emplace_back(_intervalsX, _intervalsZ, areaInfo);

	double I;
	setVarFromSetting(setting, I, "I");
	setI(I);

	splitIntervals(_intervalsX, _intervalsXForSplit, _x);
	splitIntervals(_intervalsZ, _intervalsZForSplit, _z);
}

MeshInfo::MeshInfo(const std::vector<double> _x, const std::vector<double> _z, const std::vector<IntervalForSplit> _intervalsXForSplit, const std::vector<IntervalForSplit> _intervalsZForSplit, double I, const std::vector<AreaInfo> areasInfo)
{
	splitIntervals(_intervalsX, _intervalsXForSplit, _x);
	splitIntervals(_intervalsZ, _intervalsZForSplit, _z);
	for (const AreaInfo& areaInfo : areasInfo)
		_areas.emplace_back(_intervalsX, _intervalsZ, areaInfo);
	setI(I);
}

void MeshInfo::setI(double I)
{
	if (I < 0)
		throw std::exception("I cannot be less than 0");
	_I = I;
}

double MeshInfo::getI() const
{
	return _I;
}
void MeshInfo::splitIntervals(std::vector<SplittedInterval>& splittedIntervals, const std::vector<IntervalForSplit>& intervalsForSplit, const std::vector<double>& points)
{
	splittedIntervals.reserve(intervalsForSplit.size());
	for (const IntervalForSplit& intervalForSplit : intervalsForSplit)
		splittedIntervals.emplace_back(points, intervalForSplit);
	
}

void MeshInfo::getMagneticElements(std::vector<MagnetElement>& _magneticElements) const
{	
	//std::vector<Area> areas;
	//areas.reserve(areasInfo.size());

	int elementsCount = 0;
	for (const Area& area : _areas)
		elementsCount += area.getElementsCount();
	
	_magneticElements.clear();
	_magneticElements.reserve(elementsCount);

	for (const Area& area : _areas)
		area.getElements(_magneticElements);
}

const std::vector<SplittedInterval>& MeshInfo::getIntervalsX() const
{
	return _intervalsX;
}
const std::vector<SplittedInterval>& MeshInfo::getIntervalsZ() const
{
	return _intervalsZ;
}