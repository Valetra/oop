#include "stdafx.h"
#include "ProcessDictionary.h"
#include "ProcessErrors.h"

int main(int argc, char * argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, string> dictionary;
	bool saveChanges = false;

	fstream dictionaryFile(argv[1], ios::in);
	if (!IsValidInputFile(argv[1], argc, dictionaryFile))
	{
		dictionaryFile.close();
		return EXIT_FAILURE;
	}
	else
	{
		ProcessWords(dictionary, saveChanges, dictionaryFile);
		dictionaryFile.close();

		//«апись нового(обновленного) контейнера в словарь
		WriteDictionaryToFile(dictionary, saveChanges, argv[1]);
	}
	return 0;
}