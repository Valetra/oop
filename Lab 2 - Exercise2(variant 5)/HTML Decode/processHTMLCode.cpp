#include "stdafx.h"

string HtmlDecode(string const &inputLine)
{
	string decodeString;

	for (size_t i = 0; i < inputLine.size(); ++i)
	{
		if (inputLine[i] == '&')
		{
			if (inputLine.size() > i + 5 && inputLine[i + 1] == 'q' && inputLine[i + 2] == 'u' && inputLine[i + 3] == 'o' && inputLine[i + 4] == 't' && inputLine[i + 5] == ';')
			{
				decodeString += '"';
				i += 5;
			}
			else if (inputLine.size() > i + 5 && inputLine[i + 1] == 'a' && inputLine[i + 2] == 'p' && inputLine[i + 3] == 'o' && inputLine[i + 4] == 's' && inputLine[i + 5] == ';')
			{
				decodeString += '`';
				i += 5;
			}
			else if (inputLine.size() > i + 3 && inputLine[i + 1] == 'l' && inputLine[i + 2] == 't' && inputLine[i + 3] == ';')
			{
				decodeString+= '<';
				i += 3;
			}
			else if (inputLine.size() > i + 3 && inputLine[i + 1] == 'g' && inputLine[i + 2] == 't' && inputLine[i + 3] == ';')
			{
				decodeString+= '>';
				i += 3;
			}
			else if (inputLine.size() > i + 4 && inputLine[i + 1] == 'a' && inputLine[i + 2] == 'm' && inputLine[i + 3] == 'p' && inputLine[i + 4] == ';')
			{
				decodeString+= '&';
				i += 4;
			}
			else
			{
				decodeString+= inputLine[i];
			}
		}
		else
		{
			decodeString+= inputLine[i];
		}
	}
	return decodeString;
}