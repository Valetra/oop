#include "stdafx.h"
#include "Parallelepiped.h"

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	:CBody("Parallelepiped", density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{
	if (density < 0 || width < 0 || height < 0 || depth < 0)
	{
		throw std::invalid_argument("Parameters must not be negative");
	}
}

CParallelepiped::~CParallelepiped()
{
}

double CParallelepiped::GetVolume()const
{
	return m_depth * m_width * m_height;
}

double CParallelepiped::GetWidth()const
{
	return m_width;
}

double CParallelepiped::GetHeight()const
{
	return m_height;
}

double CParallelepiped::GetDepth()const
{
	return m_depth;
}