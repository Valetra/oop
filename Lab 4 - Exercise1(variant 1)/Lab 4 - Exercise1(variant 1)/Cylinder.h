#pragma once
#include "Body.h"

class CCylinder final:
	public CBody
{
public:
	CCylinder(double density, double height, double radius);
	~CCylinder();

	double GetRadius()const;
	double GetHeight()const;
	double GetVolume()const override;

private:
	double m_height;
	double m_radius;
};