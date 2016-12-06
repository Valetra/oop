#include "Round.h"
#include "Height.h"

class CCone : public CRound, public CHeight
{
public:
	CCone(double radius, double height, double mass, double density);
	~CCone();

	std::string ToString() const;
};

