#include "MagnetismDirectTask.h"

const double PI = 3.14159265358979323846;

MagnetismDirectTask::MagnetismDirectTask(std::string configFileName) : _mesh(configFileName)
{
	_mesh.getMagneticElements(_magneticElements);
}
MagnetismDirectTask::MagnetismDirectTask(MeshInfo&& mesh) : _mesh(mesh)
{
	_mesh.getMagneticElements(_magneticElements);
}

double MagnetismDirectTask::calcMagneticIndoctionX(double x, double z)
{
	double bx = 0;
	double xMidElem, zMidElem;
	double coefX, coefZ;
	double x_, z_;
	double r2, r3;
	double buf;
	for (MagnetElement& elem : _magneticElements)
	{
		xMidElem = (elem.getIntervalX().getLeftPoint() + elem.getIntervalX().getRightPoint()) / 2;
		zMidElem = (elem.getIntervalZ().getLeftPoint() + elem.getIntervalZ().getRightPoint()) / 2;
		x_ = x - xMidElem;
		z_ = z - zMidElem;
		r2 = x_ * x_ + z_ * z_;
		r3 = pow(sqrt(r2), 3);
		coefX = 3 * x_ * x_ / r2 - 1;
		coefZ = 3 * x_ * z_ / r2;
		buf = elem.get_pX() * coefX + elem.get_pZ() * coefZ;
		bx += elem.getSquare() * _mesh.getI() / 4 / PI / r3 * buf;
	}
}

double MagnetismDirectTask::calcMagneticIndoctionY(double x, double z)
{
	double bx = 0;
	double xMidElem, zMidElem;
	double coefX, coefZ;
	double x_, z_;
	double r2, r3;
	double buf;
	for (MagnetElement& elem : _magneticElements)
	{
		xMidElem = (elem.getIntervalX().getLeftPoint() + elem.getIntervalX().getRightPoint()) / 2;
		zMidElem = (elem.getIntervalZ().getLeftPoint() + elem.getIntervalZ().getRightPoint()) / 2;
		x_ = x - xMidElem;
		z_ = z - zMidElem;
		r2 = x_ * x_ + z_ * z_;
		r3 = pow(sqrt(r2), 3);
		coefX = 3 * x_ * z_ / r2;
		coefZ = 3 * z_ * z_ / r2 - 1;
		buf = elem.get_pX() * coefX + elem.get_pZ() * coefZ;
		bx += elem.getSquare() * _mesh.getI() / 4 / PI / r3 * buf;
	}
}
