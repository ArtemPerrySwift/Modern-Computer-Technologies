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

void calcL(std::vector<std::vector<double>>& L, const std::vector<Reciver>& _recivers, MeshInfo& mesh)
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
	double r;
	for (int iReciver = 0, i = 0; iReciver < _recivers.size(); iReciver++, i += 2)
	{
		const Reciver& reciver = _recivers[iReciver];
		for (int jElem = 0, j = 0; jElem < magneticElements.size(); jElem++, j += 2)
		{
			const MagnetElement& elem = magneticElements[jElem];
		}
	}
}
void calcS(std::vector<double> S, const std::vector<Reciver>& _recivers);
