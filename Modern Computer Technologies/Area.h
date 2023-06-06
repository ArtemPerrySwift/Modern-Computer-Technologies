#pragma once
#include "SplittedInterval.h"
#include "Faces.h"
#include "AreaInfo.h"

class Area
{
	const SplittedInterval* _intervalX;
	const SplittedInterval* _intervalZ;
public:
	Area(const std::vector<SplittedInterval>& intervalsX, const std::vector<SplittedInterval>& intervalsZ, const AreaInfo& areaInfo);

	const SplittedInterval& getIntervalX() const;
	const SplittedInterval& getIntervalZ() const;

	//std::vector<GeomElement>* getGeometryElements();
	void getElements(std::vector<Rectangle>& geometryElements) const;
	int getElementsCount() const;

};

