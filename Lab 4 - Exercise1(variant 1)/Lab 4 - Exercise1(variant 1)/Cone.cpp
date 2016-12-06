#include "Cone.h"

CCone::CCone(double radius, double height, double volume, double density) : CRound(radius, volume, density), CHeight(height, volume, density)
{
}

CCone::~CCone()
{
}

std::string CCone::ToString() const
{
	std::string info = "Radius: " + std::to_string(GetRadius()) + "\n"
		+ "Volume: " + std::to_string(CBody::GetVolume()) + "\n"
		+ "Density: " + std::to_string(CBody::GetDensity()) + "\n"
		+ "Mass: " + std::to_string(CBody::GetMass()) + "\n";
	return info;
}