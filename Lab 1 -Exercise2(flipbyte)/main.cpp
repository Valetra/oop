/*Разработайте приложение flipbyte.exe, выполняющее изменение порядка
следования двоичных битов в 8-битовом целом числе (байте), заданном в
десятичном представлении, на противоположный. Для этого используйте
операторы для работы с битами. «Перевернутый» байт выводится в output
также в десятичном представлении с завершающим символом перевода строки \n.
Формат командной строки приложения:

flipbyte.exe <входной байт>

Например, в результате вызова
flipbyte.exe 6
в output должно быть выведено 96 (6(10) = 00000110(2), после изменения порядка битов данное число превратится в 01100000(2) = 9610)
Некорректные входные данные (например, передача строки, не являющейся десятичным числом, или числа, выходящего за пределы 0-255)
должно выводиться соответствующе сообщение об ошибке.

В комплекте с программой должны обязательно поставляться файлы, позволяющие проверить ее работу в автоматическом режиме
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

unsigned char Reverse(unsigned char byte)
{
	byte = (byte & 0b11110000) >> 4 | (byte & 0b00001111) << 4;
	byte = (byte & 0b11001100) >> 2 | (byte & 0b00110011) << 2;
	byte = (byte & 0b10101010) >> 1 | (byte & 0b01010101) << 1;
	return byte;
}

bool IsError(int countOfOptions, string firstOption)
{
	string digits = "0123456789";
	if (countOfOptions < 2)
	{
		cout << "Error!\nExpected Exercise2.exe <integer[0 - 255]>";
		return true;
	}

	for (unsigned int i = 0; i < firstOption.length(); ++i)
	{
		bool found = false;
		for (unsigned int j = 0; j < digits.length(); ++j)
		{
			if (firstOption[i] == digits[j])
			{
				found = true;
			}
		}
		if (found == false)
		{
			cout << "Error!\nIt was not handed over to the digital option";
			return true;
		}
	}
	return false;
}

int main(int argc, char* argv[])
{
	if (!IsError(argc, argv[1]))
	{
		string firstOption = argv[1];
		int digit = atoi(firstOption.c_str());
		if (digit >= 0 && digit <= 255)
		{
			unsigned char byte = digit;
			cout << (int)Reverse(byte) << endl;
			return 0;
		}
		else
		{
			cout << "Error!\nInvalid sourse number. Expected number from 0 to 255";
			return 1;
		}
	}
	else
	{
		return 1;
	}
	return 0;
}