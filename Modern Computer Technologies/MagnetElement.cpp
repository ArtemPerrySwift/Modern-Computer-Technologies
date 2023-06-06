#include "MagnetElement.h"

MagnetElement::MagnetElement(const IntervalRef& intervalX, const IntervalRef& intervalZ, double pX, double pZ) : _intervalX(intervalX), _intervalZ(intervalZ)
{
	set_pX(pX);
	set_pY(pY);
}
