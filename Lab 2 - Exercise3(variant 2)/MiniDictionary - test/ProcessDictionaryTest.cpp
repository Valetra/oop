#include "stdafx.h"
#include "../MiniDictionary/ProcessDictionary.h"
#include "../MiniDictionary/ProcessErrors.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ProcessDictionary_test_functions)

BOOST_AUTO_TEST_CASE(check_for_number_of_elements_in_the_map_container_and_their_value)
{
	//Предварительно в файле находятся 2 пары <ключь - значение>
	fstream inputFile("dictionary-test1.txt");
	map<string, string> dictionary;

	ReadDictionaryFromFile(inputFile, dictionary);

	BOOST_CHECK(dictionary.size() == 2);

	BOOST_CHECK(dictionary.at("hot") == "горячо");
	BOOST_CHECK(dictionary.at("cold") == "холодно");
}

BOOST_AUTO_TEST_CASE(check_the_correct_operation_of_the_functions_for_editing_the_dictionary)
{
	// Предварительно в файле находяться 2 пары <ключь - значение>

	/*dictionary-test2.txt
		кошка:cat
		кот:cat
	*/
	fstream inputFile("dictionary-test2.txt");
	map<string, string> dictionary;
	bool saveChanges = true;
	ReadDictionaryFromFile(inputFile, dictionary);
	string word1 = "dog";
	string word2 = "cat";
	string word3 = "кошка";
	string word4 = "кот";

	BOOST_CHECK(!WriteFoundWordsOfTranslation(dictionary, word1));
	BOOST_CHECK(WriteFoundWordsOfTranslation(dictionary, word2));
	BOOST_CHECK(WriteFoundWordsOfTranslation(dictionary, word3));
	BOOST_CHECK(WriteFoundWordsOfTranslation(dictionary, word4));

}

BOOST_AUTO_TEST_CASE(check_the_operation_of_the_processing_functions_of_the_dictionary_with_words_in_different_registers)
{
	// Предварительно в файле находяться 1 пара <ключь - значение>

	/*dictionary-test3.txt
		SuN:СоЛнЦе
	*/
	fstream inputFile("dictionary-test3.txt");
	map<string, string> dictionary;
	bool saveChanges = true;

	ReadDictionaryFromFile(inputFile, dictionary);
	
	string word1 = "sun";
	string word2 = "солнце";

	BOOST_CHECK(WriteFoundWordsOfTranslation(dictionary, word1));
	BOOST_CHECK(WriteFoundWordsOfTranslation(dictionary, word2));
}
BOOST_AUTO_TEST_SUITE_END()

