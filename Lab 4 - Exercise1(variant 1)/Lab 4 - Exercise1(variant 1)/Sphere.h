#include "Round.h"

class CSphere : public CRound
{
public:
	CSphere(double radius, double volume, double density);
	~CSphere();

	std::string ToString() const;
};