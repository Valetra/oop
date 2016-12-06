#include "Sphere.h"
#include "Body.h"

CSphere::CSphere(double radius, double volume, double density) : CRound(radius, volume, density)
{
}


CSphere::~CSphere()
{
}

std::string CSphere::ToString() const
{
	std::string info = "Radius: " + std::to_string(GetRadius()) + "\n"
		+ "Volume: " + std::to_string(GetVolume()) + "\n"
		+ "Density: " + std::to_string(GetDensity()) + "\n"
		+ "Mass: " + std::to_string(GetMass()) + "\n";
	return info;
}