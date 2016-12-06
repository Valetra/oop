#include "Round.h"
#include "Height.h"

class CCylinder : public CRound, public CHeight
{
public:
	CCylinder(double radius, double height, double volume, double density);
	~CCylinder();

	std::string ToString() const;
};

