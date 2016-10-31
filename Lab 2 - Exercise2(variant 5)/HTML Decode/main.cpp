#include "stdafx.h"
#include "processHTMLCode.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string inputLine;
	getline(cin, inputLine);
	cout << HtmlDecode(inputLine) << '\n';
	return 0;
}