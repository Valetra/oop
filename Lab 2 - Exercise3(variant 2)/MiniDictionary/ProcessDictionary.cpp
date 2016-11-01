#include "ProcessDictionary.h"
#include "ProcessErrors.h"

bool WriteFoundWordsOfTranslation(map<string, string> &dictionary, string &word)
{
	if (dictionary.find(word) != dictionary.end())
	{
		cout << word << " translation is " << dictionary.at(word) << '\n';
		return true;
	}
	else
	{
		bool found = false;
		for (auto wordInDictionary : dictionary)
		{
			if (word == wordInDictionary.second)
			{
				cout << wordInDictionary.second << " translation is " << wordInDictionary.first << '\n';
				found = true;
				return found;
			}
		}
		if (!found)
		{
			cout << word << " is not found\n";
			return found;
		}
	}
	return false;
}

void ReadDictionaryFromFile(fstream &dictionaryFile, map<string, string> &dictionary)
{
	string line;
	while (getline(dictionaryFile, line))
	{
		size_t i = 0;

		string firstWord;
		for (i; i < line.length() && line[i] != ':'; ++i)
		{
			firstWord += line[i];
		}

		string secondWord;
		for (++i; i < line.length(); ++i)
		{
			secondWord += line[i];
		}
		ToLowerCase(firstWord);
		ToLowerCase(secondWord);
		dictionary.insert(pair<string, string>(firstWord, secondWord));
	}
}

void ToLowerCaseRussianWord(string &word)
{
	for (size_t i = 0; i < word.length(); ++i)
	{
		switch (word[i])
		{
		case 'A':
			word[i] = 'a';
			break;
		case 'Б':
			word[i] = 'б';
			break;
		case 'В':
			word[i] = 'в';
			break;
		case 'Г':
			word[i] = 'г';
			break;
		case 'Д':
			word[i] = 'д';
			break;
		case 'Е':
			word[i] = 'е';
			break;
		case 'Ё':
			word[i] = 'ё';
			break;
		case 'Ж':
			word[i] = 'ж';
			break;
		case 'З':
			word[i] = 'з';
			break;
		case 'И':
			word[i] = 'и';
			break;
		case 'Й':
			word[i] = 'й';
			break;
		case 'К':
			word[i] = 'к';
			break;
		case 'Л':
			word[i] = 'л';
			break;
		case 'М':
			word[i] = 'м';
			break;
		case 'Н':
			word[i] = 'н';
			break;
		case 'О':
			word[i] = 'о';
			break;
		case 'П':
			word[i] = 'п';
			break;
		case 'Р':
			word[i] = 'р';
			break;
		case 'С':
			word[i] = 'с';
			break;
		case 'Т':
			word[i] = 'т';
			break;
		case 'У':
			word[i] = 'у';
			break;
		case 'Ф':
			word[i] = 'ф';
			break;
		case 'Х':
			word[i] = 'х';
			break;
		case 'Ц':
			word[i] = 'ц';
			break;
		case 'Ч':
			word[i] = 'ч';
			break;
		case 'Ш':
			word[i] = 'ш';
			break;
		case 'Щ':
			word[i] = 'щ';
			break;
		case 'Ъ':
			word[i] = 'ъ';
			break;
		case 'Ы':
			word[i] = 'ы';
			break;
		case 'Ь':
			word[i] = 'ь';
			break;
		case 'Э':
			word[i] = 'э';
			break;
		case 'Ю':
			word[i] = 'ю';
			break;
		case 'Я':
			word[i] = 'я';
			break;
		}
	}
}

void ToLowerCase(string &word)
{
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	ToLowerCaseRussianWord(word);
}

void CreateNewWord(string &word, map<string, string> &dictionary, bool &wasChanges)
{
	string answer;
	cout << "Неизвестное слово “" << word << "”. Введите перевод или пустую строку для отказа.\n";
	getline(cin, answer);
	ToLowerCase(answer);
	if (!answer.empty())
	{
		dictionary.insert(pair<string, string>(word, answer));
		cout << "Слово “" << word << "” сохранено в словаре как “" << answer << "”.\n";
		wasChanges = true;
	}
	else
	{
		cout << "Слово “" << word << "” проигнорировано.\n";
	}
}

void WriteDictionaryToFile(map<string, string> &dictionary, bool &saveChanges, string dictionaryFileName)
{
	if (saveChanges)
	{
		fstream dictionaryFile(dictionaryFileName, ios::out);
		for (map<string, string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
		{
			dictionaryFile << i->first << ":" << i->second << endl;
		}
		dictionaryFile.close();
	}
}

void ProcessWords(map<string, string> &dictionary, bool &saveChanges, fstream &dictionaryFile)
{
	ReadDictionaryFromFile(dictionaryFile, dictionary);

	string word;
	bool wasChanges = false;

	while (true)
	{
		getline(cin, word);
		if (word.empty())
		{
			cout << "Была введена пустая строка\n";
		}
		else
		{
			ToLowerCase(word);
			if (word == "..." && wasChanges)
			{
				string answer;
				cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
				getline(cin, answer);
				ToLowerCase(answer);
				if (answer == "y")
				{
					saveChanges = true;
					cout << "Изменения сохранены. До свидания.";
				}
				break;
			}
			else if (word == "..." && !wasChanges)
			{
				cout << "Словарь не был изменен. До свидания.\n";
				break;
			}
			if (dictionary.find(word) != dictionary.end())
			{
				cout << dictionary.at(word) << '\n';
			}
			else
			{
				bool found = false;
				for (auto wordInDictionary : dictionary)
				{
					if (word == wordInDictionary.second)
					{
						cout << wordInDictionary.first << '\n';
						found = true;
					}
				}
				if (!found)
				{
					CreateNewWord(word, dictionary, wasChanges);
				}
			}
		}
	}
}