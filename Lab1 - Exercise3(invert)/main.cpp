#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double matrix[3][3];

int ReadMatrixFromFile(string fileName)
{
	ifstream inputFile(fileName);
	if (inputFile.is_open())
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				inputFile >> matrix[i][j];
			}
		}
	}
	else
	{
		cout << "Файл не был открыт.";
		return 1;
	}
	return 0;
}

double CalcOfDeterminantMatrix2x2(double i1j1, double i2j1, double i1j2, double i2j2)
{
	return (i1j1 * i2j2) - (i2j1 * i1j2);
}

double CalcOfDeterminantMatrix3x3()
{
	return matrix[0][0] * (CalcOfDeterminantMatrix2x2(matrix[1][1], matrix[1][2], matrix[2][1], matrix[2][2]))
		 - matrix[0][1] * (CalcOfDeterminantMatrix2x2(matrix[1][0], matrix[1][2], matrix[2][0], matrix[2][2]))
	     + matrix[0][2] * (CalcOfDeterminantMatrix2x2(matrix[1][0], matrix[1][1], matrix[2][0], matrix[2][1]));
}



void BuildMinorMatrix()
{
	double minorMatrix[3][3];
	minorMatrix[0][0] = CalcOfDeterminantMatrix2x2(matrix[1][1], matrix[1][2], matrix[2][1], matrix[2][2]);
	minorMatrix[0][1] = CalcOfDeterminantMatrix2x2(matrix[1][0], matrix[1][2], matrix[2][0], matrix[2][2]);
	minorMatrix[0][2] = CalcOfDeterminantMatrix2x2(matrix[1][0], matrix[1][1], matrix[2][0], matrix[2][1]);
	minorMatrix[1][0] = CalcOfDeterminantMatrix2x2(matrix[0][1], matrix[0][2], matrix[2][1], matrix[2][2]);
	minorMatrix[1][1] = CalcOfDeterminantMatrix2x2(matrix[0][0], matrix[0][2], matrix[2][0], matrix[2][2]);
	minorMatrix[1][2] = CalcOfDeterminantMatrix2x2(matrix[0][0], matrix[0][1], matrix[2][0], matrix[2][1]);
	minorMatrix[2][0] = CalcOfDeterminantMatrix2x2(matrix[0][1], matrix[0][2], matrix[1][1], matrix[1][2]);
	minorMatrix[2][1] = CalcOfDeterminantMatrix2x2(matrix[0][0], matrix[0][2], matrix[1][0], matrix[1][2]);
	minorMatrix[2][2] = CalcOfDeterminantMatrix2x2(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = minorMatrix[i][j];
		}
	}
}

void PrintMatrix()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << round(matrix[i][j] * 1000) / 1000 << ' ';
		}
		cout << '\n';
	}
}

void BuildMatrixOfAlgebraicAdditions()
{
	matrix[0][1] *= -1;
	matrix[1][2] *= -1;
	matrix[2][1] *= -1;
	matrix[1][0] *= -1;
}

void ConstructTransposeMatrix()
{
	double temp;
	temp = matrix[0][1];
	matrix[0][1] = matrix[1][0];
	matrix[1][0] = temp;
	temp = matrix[0][2];
	matrix[0][2] = matrix[2][0];
	matrix[2][0] = temp;
	temp = matrix[1][2];
	matrix[1][2] = matrix[2][1];
	matrix[2][1] = temp;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 2)
	{
		cout << "Ожидался параметр - файл с матрицой 3х3\n";
		return 1;
	}
	if (ReadMatrixFromFile(argv[1]) == 1)
	{
		return 1;
	}
	cout << "Данная матрица\n";
	PrintMatrix();
	double determinant = CalcOfDeterminantMatrix3x3();
	if (determinant != 0)
	{
		cout << "\nОпределитель матрицы равен " << determinant << " и не равна 0 - это значит, что обратная матрица существует.\n";
	}
	else
	{
		cout << "\nДанная матрица не имеет обратной матрицы, потому что её определитель равен 0";
		return 1;
	}
	BuildMinorMatrix();
	cout << "\nМатрица миноров\n";
	PrintMatrix();
	cout << "\nМатрица алгебраических дополнений\n";
	BuildMatrixOfAlgebraicAdditions();
	PrintMatrix();
	cout << "\nТранспонированная матрица\n";
	ConstructTransposeMatrix();
	PrintMatrix();
	cout << "Обратная матрица\n";
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] *= -1;
		}
	}
	PrintMatrix();
	return 0;
}