#include "stdafx.h"
#include "processVector.h"

int main()
{
	bool IsWasError = false;
	std::vector<double> numbers;
	std::string inputString;
	std::getline(std::cin, inputString);
	numbers = GetNumbers(inputString, IsWasError);
	if (!IsWasError)
	{
		ProcessVector(numbers);
	}
	return EXIT_SUCCESS;
}