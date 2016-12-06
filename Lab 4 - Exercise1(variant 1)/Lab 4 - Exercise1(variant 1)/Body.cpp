#include "Body.h"

CBody::CBody(double volume, double density)
	: m_density(density)
	, m_volume(volume)
{
}

double CBody::GetDensity() const
{
	return m_density;
}


double CBody::GetVolume() const
{
	return m_volume;
}


double CBody::GetMass() const
{
	return m_volume * m_density;
}