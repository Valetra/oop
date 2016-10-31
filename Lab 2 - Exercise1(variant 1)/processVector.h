#pragma once
#include <vector>

double SumOfPositiveElements(std::vector<double> numbers);
void AddingNumberToAllElements(std::vector<double> &numbers, double number);
void ProcessVector(std::vector<double> &numbers);
std::vector<double> GetNumbers(std::string const& inputString, bool IsWasError);
bool VectorsAreEqual(std::vector<double> numbers, std::vector<double> sameNumbers);