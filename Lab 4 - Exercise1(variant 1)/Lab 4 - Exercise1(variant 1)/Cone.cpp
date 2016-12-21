#include "stdafx.h"
#include "Cone.h"


CCone::CCone(double density, double height, double radius)
	:CBody("Cone", density)
	, m_height(height)
	, m_radius(radius)
{
	if (density < 0 || radius < 0 || height < 0)
	{
		throw std::invalid_argument("Parameters must not be negative");
	}
}


CCone::~CCone()
{
}



double CCone::GetHeight()const
{
	return m_height;
}

double CCone::GetVolume()const
{
	return (1.0f / 3.0f * M_PI * pow(m_radius, 2) * m_height);
}

double CCone::GetRadius()const
{
	return m_radius;
}