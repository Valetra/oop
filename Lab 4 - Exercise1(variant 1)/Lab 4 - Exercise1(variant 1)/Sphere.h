#pragma once
#include "Body.h"

class CSphere final:
	public CBody
{
public:
	CSphere(double density, double radius);
	~CSphere();

	double CSphere::GetRadius()const;
	double CSphere::GetVolume()const override;

private:
	double m_radius;
};