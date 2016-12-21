#include "stdafx.h"
#include "Cylinder.h"



CCylinder::CCylinder(double density, double height, double radius)
	:CBody("Cylinder", density)
	, m_height(height)
	, m_radius(radius)
{
	if (density < 0 || radius < 0 || height < 0)
	{
		throw std::invalid_argument("Parameters must not be negative");
	}
}


CCylinder::~CCylinder()
{
}

double CCylinder::GetHeight()const
{
	return m_height;
}


double CCylinder::GetVolume()const
{
	return (M_PI * pow(m_radius, 2) * m_height);
}

double CCylinder::GetRadius()const
{
	return m_radius;
}