#pragma once

/*

1. ќбъ€снить почему в базовом классе CBody не используетс€ виртуальный деструктор

*/


class CBody
{
public:
	CBody(const std::string & type, double density);
	~CBody();
	double GetDensity() const;
	virtual double GetVolume() const = 0;
	double GetMass() const;
	std::string ToString() const;

private:
	double m_density;
	std::string m_type;
};