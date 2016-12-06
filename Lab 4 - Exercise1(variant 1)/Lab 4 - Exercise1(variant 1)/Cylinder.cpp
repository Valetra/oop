#include "Cylinder.h"

CCylinder::CCylinder(double radius, double height, double volume, double density) : CRound(radius, volume, density), CHeight(height, volume, density)
{
}


CCylinder::~CCylinder()
{
}

std::string CCylinder::ToString() const
{
	std::string info = "Radius: " + std::to_string(GetRadius()) + "\n"
		+ "Height: " + std::to_string(GetHight()) + "\n"
		+ "Volume: " + std::to_string(CBody::GetVolume()) + "\n"
		+ "Density: " + std::to_string(CBody::GetDensity()) + "\n"
		+ "Mass: " + std::to_string(CBody::GetMass()) + "\n";
	return info;
}