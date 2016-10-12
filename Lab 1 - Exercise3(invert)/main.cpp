#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using Matrix3x3 = double[3][3];


bool ReadMatrixFromFile(string fileName, Matrix3x3 matrix)
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
		return false;
	}
	return true;
}

double CalcOfDeterminantMatrix2x2(double i1j1, double i2j1, double i1j2, double i2j2)
{
	return (i1j1 * i2j2) - (i2j1 * i1j2);
}

double CalcOfDeterminantMatrix3x3(Matrix3x3 const& matrix)
{
	return matrix[0][0] * (CalcOfDeterminantMatrix2x2(matrix[1][1], matrix[1][2], matrix[2][1], matrix[2][2]))
		 - matrix[0][1] * (CalcOfDeterminantMatrix2x2(matrix[1][0], matrix[1][2], matrix[2][0], matrix[2][2]))
	     + matrix[0][2] * (CalcOfDeterminantMatrix2x2(matrix[1][0], matrix[1][1], matrix[2][0], matrix[2][1]));
}



void BuildMinorMatrix(Matrix3x3 matrix)
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

void PrintMatrix(Matrix3x3 const& matrix)
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

void BuildMatrixOfAlgebraicAdditions(Matrix3x3 matrix)
{
	matrix[0][1] *= -1;
	matrix[1][2] *= -1;
	matrix[2][1] *= -1;
	matrix[1][0] *= -1;
}

void ConstructTransposeMatrix(Matrix3x3 matrix)
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

void BuildInverMatrix(Matrix3x3 matrix)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] *= -1;
		}
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc != 2)
	{
		cout << "Ожидался параметр - файл с матрицой 3х3\n";
		return 1;
	}
	Matrix3x3 matrix;
	if (!ReadMatrixFromFile(argv[1], matrix))
	{
		return 1;
	}
	cout << "Данная матрица\n";
	
	PrintMatrix(matrix);
	double determinant = CalcOfDeterminantMatrix3x3(matrix);
	if (determinant != 0)
	{
		cout << "\nОпределитель матрицы равен " << determinant << " и не равна 0 - это значит, что обратная матрица существует.\n";
	}
	else
	{
		cout << "\nДанная матрица не имеет обратной матрицы, потому что её определитель равен 0";
		return 1;
	}
	BuildMinorMatrix(matrix);
	cout << "\nМатрица миноров\n";
	
	PrintMatrix(matrix);
	cout << "\nМатрица алгебраических дополнений\n";
	BuildMatrixOfAlgebraicAdditions(matrix);
	
	PrintMatrix(matrix);
	cout << "\nТранспонированная матрица\n";
	ConstructTransposeMatrix(matrix);
	
	PrintMatrix(matrix);
	cout << "Обратная матрица\n";
	BuildInverMatrix(matrix);
	PrintMatrix(matrix);
	return 0;
}