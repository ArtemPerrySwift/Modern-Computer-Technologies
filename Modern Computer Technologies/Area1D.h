#pragma once
#include <vector>
#include "Area1D_InputInfo.h"
#include "SplittedInterval.h"

class Area1D: public Area1D_info
{
private:
	const SplittedInterval* _interval;
public:
	Area1D(const std::vector<SplittedInterval>& intervals, const Area1D_InputInfo& area1D_info);
	const SplittedInterval& getInterval() const;
};

