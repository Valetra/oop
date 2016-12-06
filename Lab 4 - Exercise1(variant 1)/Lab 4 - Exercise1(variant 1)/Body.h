#pragma once
#include <string>
class CBody
{
public:
	CBody(double volume, double density);
	~CBody() = default;

	// Плотность
	double GetDensity() const;

	// Объём
	double GetVolume() const;

	// Масса
	double GetMass() const;

	// Вывод информации о теле
	virtual std::string ToString() const = 0;

private:
	// Плотность
	double m_density;
	double m_volume;
};

