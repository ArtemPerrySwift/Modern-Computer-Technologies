#pragma once
#include <array>
#include <functional>
class GausseIntegr
{
	static const std::array<double, 4> GaussePoints;
	static const std::array<double, 4> GausseWights;
public:
	double itegrate(double xLeft, double xRight, double yLeft, double yRight, std::function<double(double, double)> funct);
};
