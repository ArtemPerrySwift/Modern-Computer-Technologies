#include "ReverseTask.h"
#include <iostream>
#include "GausseIntegr.h"

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

void writeDirectTaskMeshInBinaryFile(const char* cfgFileName, const char* meshFileName)
{
	libconfig::Config cfg;
	getConfigFromFile(cfg, cfgFileName);
	MeshInfo mesh(cfg);
	MagnetismDirectTask directTask(mesh);
	mesh.writeMagneticElementsInBinaryFile(meshFileName);
}

void makeDirectTask(const char* cfgFileName, double left, double right, int nRecivers, const char* reciversFileName)
{
	libconfig::Config cfg;
	getConfigFromFile(cfg, cfgFileName);
	MeshInfo mesh(cfg);
	MagnetismDirectTask directTask(mesh);

	if (left > right)
		std::swap(left, right);
	int nIntervals = nRecivers - 1;
	double h = (right - left) / nIntervals;

	std::ofstream out;
	out.open(reciversFileName, std::ios::binary);
	out.write((char*)&nRecivers, sizeof(nRecivers));

	double x;
	double z = 0;
	double bx, bz;

	for (int i = 0; i < nIntervals; i++)
	{
		x = left + i * h;
		bx = directTask.calcMagneticIndoctionX(x, z);
		bz = directTask.calcMagneticIndoctionY(x, z);

		out.write((char*)&x, sizeof(x));
		out.write((char*)&z, sizeof(z));
		out.write((char*)&bx, sizeof(bx));
		out.write((char*)&bz, sizeof(bz));
	}
	x = right;

	bx = directTask.calcMagneticIndoctionX(x, z);
	bz = directTask.calcMagneticIndoctionY(x, z);

	out.write((char*)&x, sizeof(x));
	out.write((char*)&z, sizeof(z));
	out.write((char*)&bx, sizeof(bx));
	out.write((char*)&bz, sizeof(bz));
	out.close();
}

void makeDirectTask(const char* cfgFileName, double xLeft, double xRight, double zLeft, double zRight, int nRecivers, const char* reciversFileName)
{
	libconfig::Config cfg;
	getConfigFromFile(cfg, cfgFileName);
	MeshInfo mesh(cfg);

	MagnetismDirectTask directTask(mesh);

	if (xLeft > xRight)
		std::swap(xLeft, xRight);

	if (zLeft > zRight)
		std::swap(zLeft, zRight);

	int nIntervals = nRecivers - 1;

	double hx = (xRight - xLeft) / nIntervals;
	double hz = (zRight - zLeft) / nIntervals;

	std::ofstream out;
	out.open(reciversFileName, std::ios::binary);
	out.write((char*)&nRecivers, sizeof(nRecivers));

	double x, z;
	double bx, bz;

	for (int i = 0; i < nIntervals; i++)
	{
		x = xLeft + i * hx;
		z = xLeft + i * hz;
		bx = directTask.calcMagneticIndoctionX(x, z);
		bz = directTask.calcMagneticIndoctionY(x, z);
		out.write((char*)&x, sizeof(x));
		out.write((char*)&z, sizeof(z));
		out.write((char*)&bx, sizeof(bx));
		out.write((char*)&bz, sizeof(bz));
	}
	x = xRight;
	z = zRight;

	bx = directTask.calcMagneticIndoctionX(x, z);
	bz = directTask.calcMagneticIndoctionY(x, z);

	out.write((char*)&x, sizeof(x));
	out.write((char*)&z, sizeof(z));
	out.write((char*)&bx, sizeof(bx));
	out.write((char*)&bz, sizeof(bz));

	out.close();
}

void makeReverseTask(const char* cfgFileName, const char* reciversFileName, const char* ansFileName, double alpha)
{
	libconfig::Config cfgRev;
	getConfigFromFile(cfgRev, cfgFileName);

	MeshInfo meshRev(cfgRev);

	ReverseTask reverseTask(alpha);

	std::vector<Reciver> recivers;
	Reciver::readRecivers(recivers, reciversFileName);

	reverseTask.countSolution(recivers, meshRev);

	meshRev.writeMagneticElementsInBinaryFile(ansFileName);
}
int main()
{
	libconfig::Config cfg;
	getConfigFromFile(cfg, "DirectTask.cfg");
	MeshInfo mesh(cfg);
	MagnetismDirectTask directTask(mesh);
	writeInBinaryFileRecivers(-500, 500, 500, directTask, "ReciversData.bin");
	//riteBInConsole(-500, 500, 500, directTask);
	libconfig::Config cfgRev;
	getConfigFromFile(cfgRev, "ReverseTask.cfg");
	MeshInfo meshRev(cfgRev);
	ReverseTask reverseTask(0);
	std::vector<Reciver> recivers;
	Reciver::readRecivers(recivers, "ReciversData.bin");
	reverseTask.countSolution(recivers, meshRev);
	MagnetismDirectTask directTaskcheck(meshRev);

	double err = 0;
	for (const Reciver& rec : recivers)
	{
		std::cout << rec.getX() << "\t" << rec.getBx() << "\t" << directTaskcheck.calcMagneticIndoctionX(rec.getX(), rec.getZ()) << std::endl;
		err += pow((rec.getBx() - directTaskcheck.calcMagneticIndoctionX(rec.getX(), rec.getZ())), 2);
	}
	
	std::cout << "Error = " << err << std::endl;

	
	//double integral = GausseIntegr::integrate(0, 1, 0, 1, [](double x, double y) {return x*x + 8 * y * y; });
	//std::cout << integral;
	//meshRev.writeMagneticElementsInBinaryFile("Ans.bin");
	for (const MagnetElement& elem : meshRev.getMagneticElements())
	{
		std::cout << elem.get_pX() << " " << elem.get_pZ() << std::endl;
	}
	//makeDirectTask("DirectTask.cfg", 0, 1000, 500, "ReciversData.bin");
	return 0;
}