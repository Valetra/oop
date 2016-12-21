#include "stdafx.h"
#include "Sphere.h"


CSphere::CSphere(double density, double radius)
	:CBody("Sphere", density)
		, m_radius(radius)
{
	if (density < 0 || radius < 0)
	{
		throw std::invalid_argument("Parameters must not be negative");
	}
	
}


CSphere::~CSphere()
{
}


double CSphere::GetRadius()const
{
	return m_radius;
}

double CSphere::GetVolume()const
{
	return (pow(m_radius, 3) * M_PI) * 4.0f / 3.0f;
}