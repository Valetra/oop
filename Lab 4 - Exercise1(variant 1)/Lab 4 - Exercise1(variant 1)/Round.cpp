#include "Round.h"

CRound::CRound(double radius, double volume, double density) : CBody(volume, density),
	m_radius(radius)
{
}


CRound::~CRound()
{
}


// Возвращает радиус
double CRound::GetRadius() const
{
	return m_radius;
}
