#include "stdafx.h"

static const size_t MAX_ARGC_COUNT = 2;

bool IsValidCountOfArguments(int argc)
{
	return (argc == MAX_ARGC_COUNT);
}

bool IsFileExists(fstream &file)
{
	return file.good();
}

bool IsFileEmpty(fstream &file)
{
	return file.peek() == ifstream::traits_type::eof();
}

bool IsValidInputFile(char* inputFileName, size_t argc, fstream &inputFile)
{
	if (!IsFileExists(inputFile))
	{
		cout << "File \"" << inputFileName << "\" not exists" << "\n";
		return false;
	}
	if (IsFileEmpty(inputFile))
	{
		cout << "File \"" << inputFileName << "\" is empty" << "\n";
		return true;
	}
	if (!IsValidCountOfArguments(argc))
	{
		cout << "Expected one argument - dictionary.txt\n";
		return false;
	}
	return true;
}