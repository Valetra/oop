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

unsigned char ReverseBytes(unsigned char byte)
{
	byte = (byte & 0xF0) >> 4 | (byte & 0x0F) << 4;
	byte = (byte & 0xCC) >> 2 | (byte & 0x33) << 2;
	byte = (byte & 0xAA) >> 1 | (byte & 0x55) << 1;
	return byte;
}

bool CheckArguments(int countOfOptions, string firstOption)
{
	string digits = "0123456789";
	if (countOfOptions != 2)
	{
		cout << "Error!\nExpected Exercise2.exe <integer[0 - 255]>";
		return false;
	}

	for (unsigned int i = 0; i < firstOption.length(); ++i)
	{
		if (!isdigit(firstOption[i]))
		{
			cout << "Error!\nIt was not handed over to the digital option";
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (!CheckArguments(argc, argv[1]))
	{
		return 1;
	}
	else
	{
		string firstOption = argv[1];
		int digit = atoi(firstOption.c_str());
		if (digit >= 0 && digit <= 255)
		{
			unsigned char byte = digit;
			cout << static_cast<int>(ReverseBytes(byte));
			return 0;
		}
		else
		{
			cout << "Error!\nInvalid sourse number. Expected number from 0 to 255";
			return 1;
		}
	}
}