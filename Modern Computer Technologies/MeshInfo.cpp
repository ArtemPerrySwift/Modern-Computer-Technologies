#include "MeshInfo.h"
#include <algorithm>
MeshInfo::MeshInfo(libconfig::Config& config) : MeshInfo(getSettingFromConfig(config, "Mesh")) {}

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
	libconfig::Setting& basePointsSetting = getSubSetting(setting, "BasePoints");
	setArrayFromConfigArray(basePointsSetting, _x, "X");
	checkBasePointsArr(_x, "X");
	setArrayFromConfigArray(basePointsSetting, _z, "Z");
	checkBasePointsArr(_z, "Z");
	libconfig::Setting& intervalSetting = getSubSetting(setting, "Intervals");
	setArrayFromConfigList(intervalSetting, _intervalsXForSplit, "X");
	setArrayFromConfigList(intervalSetting, _intervalsZForSplit, "Z");
	setArrayFromConfigList(setting, _areas, "Areas");
}
