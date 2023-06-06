#include "Area1D_info.h"

const BoundaryCondition& Area1D_info::getConditionForFirstIntervalPoint() const
{
	return _conditionForLeftBoundary;
}

const BoundaryCondition& Area1D_info::getConditionForSecondIntervalPoint() const
{
	return _conditionForRightBoundary;
}