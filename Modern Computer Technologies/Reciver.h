#pragma once
#include <sstream>
struct Reciver
{
	double x;
	double z;
	double Bx;
	double Bz;

	Reciver();
	Reciver(std::istream& in);
	void read(std::istream& in);

	double getX() const;
	double getZ() const;
	double getBx() const;
	double getBz() const;
};

