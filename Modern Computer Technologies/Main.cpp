#include "ReverseTask.h"
#include <iostream>
int main()
{
	MeshInfo mesh("DirectTask.cfg");
	MagnetismDirectTask directTask(mesh);
	std::cout << directTask.calcMagneticIndoctionX(200, 0);
	return 0;
}