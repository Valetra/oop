#include "stdafx.h"

void ProcessWords(map<string, string> &dictionary, bool &saveChanges, fstream &dictionaryFile);
void WriteDictionaryToFile(map<string, string> &dictionary, bool &saveChanges, string dictionaryFileName);
void ReadDictionaryFromFile(fstream &dictionaryFile, map<string, string> &dictionary);
bool WriteFoundWordsOfTranslation(map<string, string> &dictionary, string &word);
void ToLowerCase(string &word);