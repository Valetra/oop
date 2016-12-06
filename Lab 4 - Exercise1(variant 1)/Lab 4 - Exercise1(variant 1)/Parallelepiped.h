#include "Height.h"

class CParallelepiped : public CHeight
{
public:
	CParallelepiped(double height, double width, double depth, double volume, double density);
	~CParallelepiped();
	// Возвращает ширину
	double GetWidth() const;
	// Возвращает глубину
	double GetDepth() const;

	std::string ToString() const;
private:
	// Ширина
	double m_width;
	// Глубина
	double m_depth;
};

