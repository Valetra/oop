#ifndef ROUND_H
#define ROUND_H

#include "Body.h"

class CRound : public CBody
{
public:
	CRound(double radius, double volume, double density);
	~CRound();
	// Возвращает радиус
	double GetRadius() const;

private:
	// Радиус
	double m_radius;
};
#endif