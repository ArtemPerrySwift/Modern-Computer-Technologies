#include "ReverseTask.h"

ReverseTask::ReverseTask(double alpha)
{

}
void ReverseTask::countSolution(const std::vector<Reciver>& _recivers, MeshInfo& mesh) const
{

}
void ReverseTask::setAlpha(double alpha)
{
	if (alpha < 0)
		throw std::exception("Alpha parameter for regularization cannot be less then 0");

	_alpha = alpha;
}
double ReverseTask::getAlpha() const
{
	return _alpha;
}

void ReverseTask::calcL(std::vector<std::vector<double>>& L, const std::vector<Reciver>& _recivers, MeshInfo& mesh)
{
	const std::vector<MagnetElement>& magneticElements = mesh.getMagneticElements();
	int rowCount, columnCount;
	columnCount = 2 * magneticElements.size();
	rowCount = 2 * _recivers.size();
	L.resize(rowCount);
	for (std::vector<double>& Li : L)
		Li.resize(columnCount);
	
	double xMidElem, zMidElem;
	double coefX, coefZ;
	double x_, z_;
	double r2;
	for (int iReciver = 0, i = 0; iReciver < _recivers.size(); iReciver++, i += 2)
	{
		const Reciver& reciver = _recivers[iReciver];
		for (int jElem = 0, j = 0; jElem < magneticElements.size(); jElem++, j += 2)
		{
			const MagnetElement& elem = magneticElements[jElem];
			xMidElem = (elem.getIntervalX().getLeftPoint() + elem.getIntervalX().getRightPoint()) / 2;
			zMidElem = (elem.getIntervalZ().getLeftPoint() + elem.getIntervalZ().getRightPoint()) / 2;
			x_ = reciver.getX() - xMidElem;
			z_ = reciver.getZ() - zMidElem;
			r2 = x_ * x_ + z_ * z_;
			L[i    ][j    ] = 3 * x_ * x_ / r2 - 1;
			L[i    ][j + 1] = 3 * x_ * z_ / r2;
			L[i + 1][j    ] = 3 * x_ * z_ / r2;
			L[i + 1][j + 1] = 3 * z_ * z_ / r2 - 1;
		}
	}
}

void ReverseTask::calcS(std::vector<double> S, const std::vector<Reciver>& _recivers)
{
	S.resize(2 * _recivers.size());
	for (int iReciver = 0, i = 0; iReciver < _recivers.size(); iReciver++, i += 2)
	{
		S[i    ] = _recivers[iReciver].getBx();
		S[i + 1] = _recivers[iReciver].getBz();
	}
}

void ReverseTask::addAlpha(std::vector<std::vector<double>>& Matrix)
{
	for (int i = 0; i < Matrix.size(); i++)
		Matrix[i][i] += _alpha;
}
