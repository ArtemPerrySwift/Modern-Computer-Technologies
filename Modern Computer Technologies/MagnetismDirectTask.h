#pragma once
#include "MeshInfo.h"
class MagnetismDirectTask
{
private:
	MeshInfo _mesh;
	std::vector<MagnetElement> _magneticElements;
public:
	MagnetismDirectTask(std::string configFileName);
	MagnetismDirectTask(MeshInfo&& mesh);
	double calcMagneticIndoctionX(double x, double z);
	double calcMagneticIndoctionY(double x, double z);
};

