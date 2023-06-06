#pragma once
#include "Area1D.h"
#include "SplittedInterval.h"
#include "GeomElement.h"

class Area
{
	Area1D areaX;
	Area1D areaY;
	Area1D areaZ;
public:
	Area(const std::vector<SplittedInterval>& intervalsX, const Area1D_InputInfo& areaX_info,
		const std::vector<SplittedInterval>& intervalsY, const Area1D_InputInfo& areaY_info,
		const std::vector<SplittedInterval>& intervalsZ, const Area1D_InputInfo& areaZ_info);

	const Area1D& getAreaX() const; 
	const Area1D& getAreaY() const;
	const Area1D& getAreaZ() const;

	//std::vector<GeomElement>* getGeometryElements();
	void getGeometryElements(std::vector<Cuboid>& geometryElements) const;
	int getGeometryElementsCount() const;

};

