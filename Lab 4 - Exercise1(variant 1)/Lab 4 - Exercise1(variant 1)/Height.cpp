#include "Height.h"



CHeight::CHeight(double height, double volume, double density) : CBody(volume, density)
	, m_height(height)
{
}


CHeight::~CHeight()
{
}


// Возвращает высоту
double CHeight::GetHight() const
{
	return m_height;
}
