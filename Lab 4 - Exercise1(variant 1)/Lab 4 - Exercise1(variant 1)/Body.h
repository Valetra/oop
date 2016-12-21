#pragma once

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