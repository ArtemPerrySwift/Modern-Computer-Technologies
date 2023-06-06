#include "Reciver.h"

Reciver::Reciver()
{
	x = z = 1;
	Bx = Bz = 0;
}

Reciver::Reciver(std::istream& in)
{
	read(in);
}

void Reciver::read(std::istream& in)
{
	in.read((char*)&x, sizeof(x));
	if (in.fail())
		throw std::exception("Cannot read x coordinate of reciver");

	in.read((char*)&z, sizeof(z));
	if (in.fail())
		throw std::exception("Cannot read y coordinate of reciver");

	in.read((char*)&Bx, sizeof(Bx));
	if (in.fail())
		throw std::exception("Cannot read x magnetic value in reciver");

	in.read((char*)&Bz, sizeof(Bz));
	if (in.fail())
		throw std::exception("Cannot read y magnetic value in reciver");
}

double Reciver::getX() const
{
	return x;
}
double Reciver::getZ() const
{
	return z;
}
double Reciver::getBx() const
{
	return Bx;
}
double Reciver::getBz() const
{
	return Bz;
}
