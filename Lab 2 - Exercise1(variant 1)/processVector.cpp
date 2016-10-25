#pragma once
#include "stdafx.h"

double SumOfPositiveElements(std::vector<double> numbers)
{
	double sum = 0;
	double average = 0;
	int positiveNumbersCount = 0;
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		if (numbers.at(i) > 0)
		{
			sum += round(numbers.at(i) * 1000.0f) / 1000.0f;
			positiveNumbersCount++;
		}
	}
	return average = sum / positiveNumbersCount;
}

void AddingNumberToAllElements(std::vector<double> &numbers, double number)
{
	boost::transform(numbers, numbers.begin(), bind(std::plus<double>(), _1, number));
}

void ProcessVector(std::vector<double> &numbers)
{
	AddingNumberToAllElements(numbers, SumOfPositiveElements(numbers));
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, ", "));
}