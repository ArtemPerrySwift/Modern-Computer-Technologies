#pragma once
#include "MagnetismDirectTask.h"
#include "Reciver.h"
class ReverseTask
{
private:
	double _alpha;
	void calcL(std::vector<std::vector<double>>& L, const std::vector<Reciver>& _recivers, MeshInfo& mesh);
	void calcS(std::vector<double> S, const std::vector<Reciver>& _recivers);
public:
	ReverseTask(double alpha);
	void countSolution(const std::vector<Reciver>& _recivers, MeshInfo& mesh) const;
	void setAlpha(double alpha);
	double getAlpha() const;
};

