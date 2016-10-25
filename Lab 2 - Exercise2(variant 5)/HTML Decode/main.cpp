#include <iostream>
#include <string>

using namespace std;

string HtmlDecode(string const &inputLine)
{
	size_t j = 0;
	string decodeString;
	decodeString.resize(inputLine.size());

	for (size_t i = 0; i < inputLine.size(); ++i)
	{
		if (inputLine[i] == '&')
		{
			if (inputLine.size() > i + 5 && inputLine[i + 1] == 'q' && inputLine[i + 2] == 'u' && inputLine[i + 3] == 'o' && inputLine[i + 4] == 't' && inputLine[i + 5] == ';')
			{
				decodeString[j] = '"';
				i += 5;
				++j;
			}
			else if (inputLine.size() > i + 5 && inputLine[i + 1] == 'a' && inputLine[i + 2] == 'p' && inputLine[i + 3] == 'o' && inputLine[i + 4] == 's' && inputLine[i + 5] == ';')
			{
				decodeString[j] = '`';
				i += 5;
				++j;
			}
			else if(inputLine.size() > i + 3 && inputLine[i + 1] == 'l' && inputLine[i + 2] == 't' && inputLine[i + 3] == ';')
			{
				decodeString[j] = '<';
				i += 3;
				++j;
			}
			else if (inputLine.size() > i + 3 && inputLine[i + 1] == 'g' && inputLine[i + 2] == 't' && inputLine[i + 3] == ';')
			{
				decodeString[j] = '>';
				i += 3;
				++j;
			}
			else if (inputLine.size() > i + 4 && inputLine[i + 1] == 'a' && inputLine[i + 2] == 'm' && inputLine[i + 3] == 'p' && inputLine[i + 4] == ';')
			{
				decodeString[j] = '&';
				i += 4;
				++j;
			}
			else
			{
				decodeString[j] = inputLine[i];
				++j;
			}
		}
		else
		{
			decodeString[j] = inputLine[i];
			++j;
		}
	}
	return decodeString;
}

int main()
{
	string inputLine;
	getline(cin, inputLine);
	cout << HtmlDecode(inputLine) << '\n';
	return 0;
}