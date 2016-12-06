#include "Parallelepiped.h"



CParallelepiped::CParallelepiped(double height, double width, double depth, double volume, double density) : CHeight(height, volume, density)
, m_width(0)
, m_depth(0)
{
	m_width = width;
	m_depth = depth;
}


CParallelepiped::~CParallelepiped()
{
}


// Возвращает ширину
double CParallelepiped::GetWidth() const
{
	return m_width;
}

// Возвращает глубину
double CParallelepiped::GetDepth() const
{
	return m_depth;
}

std::string CParallelepiped::ToString() const
{
	std::string info = "Height: " + std::to_string(GetHight()) + "\n"
		+ "Width: " + std::to_string(GetWidth()) + "\n"
		+ "Depth: " + std::to_string(GetDepth()) + "\n"
		+ "Volume: " + std::to_string(CBody::GetVolume()) + "\n"
		+ "Density: " + std::to_string(CBody::GetDensity()) + "\n"
		+ "Mass: " + std::to_string(CBody::GetMass()) + "\n";
	return info;
}