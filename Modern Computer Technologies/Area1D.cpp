#include "Area1D.h"

Area1D::Area1D(const std::vector<SplittedInterval>& intervals, const Area1D_InputInfo& area1D_info) : Area1D_info(area1D_info)
{
	if (area1D_info.getIntervalNum() >= intervals.size())
		throw std::exception("Interval number fo area cannot be greater then intervals count");
	_interval = &(intervals[area1D_info.getIntervalNum()]);
}

const SplittedInterval& Area1D::getInterval() const
{
	return *_interval;
}
