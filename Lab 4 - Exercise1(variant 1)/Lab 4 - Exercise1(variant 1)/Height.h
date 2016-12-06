#ifndef HEIGHT_H
#define HEIGHT_H

#include "Body.h"

class CHeight : public CBody
{
public:
	CHeight(double height, double volume, double density);
	~CHeight();
	// Возвращает высоту
	double GetHight() const;

private:
	// Высота
	double m_height;
};
#endif