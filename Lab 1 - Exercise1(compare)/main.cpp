#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

bool IsFilesEquals(ifstream &file1, ifstream &file2)
{
	string str1;
	string str2;
	bool equal = true;
	int i = 0;
	while (!file1.eof() && equal)
	{
		getline(file1, str1);
		getline(file2, str2);
		i++;
		if (str1 != str2)
		{
			equal = false;
			cout << "Files are different." << '\n' << "Line number is " << i << '\n';
		}
	}
	if (equal)
	{
		cout << "Files are equal";
	}
	return equal;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Using exercise1.exe <file1> <file2>" << endl;
		return 1;
	}

	setlocale(LC_ALL, "rus");
	string fileName1 = argv[1];
	string fileName2 = argv[2];
	ifstream file1, file2;
	file1.open(fileName1, ios::binary);
	file2.open(fileName2, ios::binary);
	if (!file1.is_open() || !file2.is_open())
	{
		cout << "Failed to open one of files for reading" << endl;
		return 1;
	}
	//Сравнение файлов построчно
	return !IsFilesEquals(file1, file2);
}