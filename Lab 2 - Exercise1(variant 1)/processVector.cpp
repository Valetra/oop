#pragma once
#include "stdafx.h"
#include <stdexcept>

bool VectorsAreEqual(std::vector<double> numbers, std::vector<double> sameNumbers)
{
	if (numbers.size() != sameNumbers.size())
	{
		return false;
	}
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		if (numbers.at(i) != sameNumbers.at(i))
		{
			return false;
		}
	}
	return true;
}

std::vector<double> GetNumbers(std::string const& inputString, bool IsWasError)
{
	std::vector<double> numbers;
	if (!inputString.empty())
	{
		std::vector<std::string> resultSplit;
		boost::split(resultSplit, inputString, boost::is_any_of(" "));

		for (auto split : resultSplit)
		{
			int n;
			try
			{
				n = boost::lexical_cast<int>(split);
			}
			catch (boost::bad_lexical_cast)
			{
				std::cout << "Bad value" << std::endl;
				IsWasError = true;
				return numbers;
			}
			numbers.push_back(n);
		}
	}
	return numbers;
}

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
	if (positiveNumbersCount != 0)
	{
		return average = sum / positiveNumbersCount;
	}
	else
	{
		return 0;
	}
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
	std::cout << '\n';
}