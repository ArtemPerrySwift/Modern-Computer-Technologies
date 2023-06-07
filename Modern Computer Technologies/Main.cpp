#include "ReverseTask.h"
#include <iostream>
int main()
{
	libconfig::Config cfg;
	getConfigFromFile(cfg, "DirectTask.cfg");
	MeshInfo mesh(cfg);
	MagnetismDirectTask directTask(mesh);
	std::cout << directTask.calcMagneticIndoctionX(200, 0);
	return 0;
}