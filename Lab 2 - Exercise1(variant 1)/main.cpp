#include "stdafx.h"

int main()
{
	std::vector<double> numbers(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));
	ProcessVector(numbers);
	return 0;
}