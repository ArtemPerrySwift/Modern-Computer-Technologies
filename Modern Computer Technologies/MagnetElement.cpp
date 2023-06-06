#include "MagnetElement.h"

MagnetElement::MagnetElement(const IntervalRef& intervalX, const IntervalRef& intervalZ, double pX, double pZ) : FaceXZ(intervalX, intervalZ), MagnetInfo(pX, pZ) {}
