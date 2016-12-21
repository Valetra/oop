#pragma once
#include "Body.h"

class CCone final:
	public CBody
{
public:
	CCone(double density, double height, double radius);
	~CCone();

	double GetRadius()const;
	double GetHeight()const;
	double GetVolume()const override;

private:
	double m_height;
	double m_radius;
};