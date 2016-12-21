#pragma once
#include "Body.h"

class CParallelepiped final:
	public CBody
{
public:
	CParallelepiped(double density, double width, double height, double depth);
	~CParallelepiped();

	double CParallelepiped::GetVolume()const override;
	double CParallelepiped::GetWidth()const;
	double CParallelepiped::GetHeight()const;
	double CParallelepiped::GetDepth()const;

private:
	double m_width;
	double m_height;
	double m_depth;
};