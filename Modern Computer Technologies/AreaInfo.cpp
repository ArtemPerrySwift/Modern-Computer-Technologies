#include "AreaInfo.h"

AreaInfo::AreaInfo( Area1D_InputInfo intervalX_ConditionsYZ,
			Area1D_InputInfo intervalY_ConditionsXZ,
			Area1D_InputInfo intervalZ_ConditionsXY) :
			_intervalX_ConditionsYZ(intervalX_ConditionsYZ), 
			_intervalY_ConditionsXZ(intervalY_ConditionsXZ), 
			_intervalZ_ConditionsXY(intervalZ_ConditionsXY) {}

AreaInfo::AreaInfo(std::istream& in) :  
	_intervalX_ConditionsYZ(in),
	_intervalY_ConditionsXZ(in),
	_intervalZ_ConditionsXY(in) {}


AreaInfo::AreaInfo(libconfig::Setting& setting) :
	_intervalX_ConditionsYZ(getSubSetting(setting, "IntervX_ConditYZ")),
	_intervalY_ConditionsXZ(getSubSetting(setting, "IntervY_ConditXZ")),
	_intervalZ_ConditionsXY(getSubSetting(setting, "IntervZ_ConditXY")) {}
