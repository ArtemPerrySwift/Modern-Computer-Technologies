#pragma once
#include "IntervalForSplit.h"
#include "BoundaryCondition.h"

class Area1D_info
{
public:
	BoundaryCondition _conditionForLeftBoundary;
	BoundaryCondition _conditionForRightBoundary;
	const BoundaryCondition& getConditionForFirstIntervalPoint() const;
	const BoundaryCondition& getConditionForSecondIntervalPoint() const;
};

