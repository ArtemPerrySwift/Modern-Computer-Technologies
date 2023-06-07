#include "ReverseTask.h"
#include <iostream>

void writeInBinaryFileRecivers(double left, double right, int nRecivers, const MagnetismDirectTask& dirctTask, std::string outFileName)
{
	int nIntervals = nRecivers - 1;
	double h = (right - left) / nIntervals;
	std::ofstream out;
	out.open(outFileName, std::ios::binary);
	out.write((char*)&nRecivers, sizeof(nRecivers));
	double x;
	double z = 0;
	double bx, bz;
	for (int i = 0; i < nIntervals; i++)
	{
		x = left + i * h;
		bx = dirctTask.calcMagneticIndoctionX(x, z);
		bz = dirctTask.calcMagneticIndoctionY(x, z);
		out.write((char*)&x, sizeof(x));
		out.write((char*)&z, sizeof(z));
		out.write((char*)&bx, sizeof(bx));
		out.write((char*)&bz, sizeof(bz));
	}
	x = right;
	bx = dirctTask.calcMagneticIndoctionX(x, z);
	bz = dirctTask.calcMagneticIndoctionY(x, z);
	out.write((char*)&x, sizeof(x));
	out.write((char*)&z, sizeof(z));
	out.write((char*)&bx, sizeof(bx));
	out.write((char*)&bz, sizeof(bz));
	out.close();
}

void writeBInConsole(double left, double right, int nRecivers, const MagnetismDirectTask& dirctTask)
{
	int nIntervals = nRecivers - 1;
	double h = (right - left) / nIntervals;
	std::cout.write((char*)&nRecivers, sizeof(nRecivers));
	double x;
	double z = 0;
	for (int i = 0; i < nIntervals; i++)
	{
		x = left + i * h;
		std::cout << x << " " << dirctTask.calcMagneticIndoctionX(x, z) << " " << dirctTask.calcMagneticIndoctionY(x, z) << std::endl;
	}
	x = right;
	std::cout << x << " " << dirctTask.calcMagneticIndoctionX(x, z) << " " << dirctTask.calcMagneticIndoctionY(x, z) << std::endl;
}
int main()
{
	libconfig::Config cfg;
	getConfigFromFile(cfg, "DirectTask.cfg");
	MeshInfo mesh(cfg);
	MagnetismDirectTask directTask(mesh);
	writeInBinaryFileRecivers(-500, 500, 500, directTask, "ReciversData.bin");
	writeBInConsole(-500, 500, 500, directTask);
	libconfig::Config cfgRev;
	getConfigFromFile(cfgRev, "ReverseTask.cfg");
	MeshInfo meshRev(cfgRev);
	ReverseTask reverseTask(0);
	std::vector<Reciver> recivers;
	Reciver::readRecivers(recivers, "ReciversData.bin");
	reverseTask.countSolution(recivers, meshRev);
	for (const MagnetElement& elem : meshRev.getMagneticElements())
	{
		std::cout << elem.get_pX() << " " << elem.get_pZ() << std::endl;
	}
	
	return 0;
}