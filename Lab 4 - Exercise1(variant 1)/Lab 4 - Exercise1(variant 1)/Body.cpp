#include "stdafx.h"
#include "Body.h"

CBody::CBody(const std::string & type, double density)
	: m_density(density)
	, m_type(type)
{
}


CBody::~CBody()
{
}


double CBody::GetDensity() const
{
	return m_density;
}

double CBody::GetMass() const
{
	return GetVolume() * GetDensity();
}


std::string CBody::ToString() const
{
	std::string info;
	info = "\n\tDensity of body is: " + std::to_string(GetDensity()) + "\n"
		+ "\tVolume of body is: " + std::to_string(GetVolume()) + "\n"
		+ "\tMass of body is: " + std::to_string(GetMass()) + "\n";
	return info;
}
