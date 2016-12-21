#pragma once

#include <iostream>

//Класс, моделирующий рациональное число

class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	// Возвращает числитель
	int GetNumerator() const;

	// Возвращает знаменатель
	int GetDenominator() const;

	// Устанавливает новое значение числителя
	void SetNumerator(int numerator);

	// Устанавливает новое значение знаменателя
	void SetDenominator(int denominator);

	// Возвращает отношение числителя и знаменателя в виде числа double
	double ToDouble() const;

	// Возвращает рациональное число, равное текущему
	const CRational operator+() const;

	// Возвращает раицональное число с обратным знаком числителя
	const CRational operator-() const;

	// Выполняет увеличение рационального числа на величину второго рационального,
	//	либо целого числа:
	CRational & operator+=(CRational const& r);

	// Выполняет уменьшение рационального числа на величину второго рационального либо целого числа :
	CRational & operator-=(CRational const& r);

	// Умножает значение первого рационального числа на другое рациональное, 
	//	либо целое:
	CRational & operator*=(CRational const& r);

	// Делит первое рациональное число на другое рациональное, 
	//	либо целое:
	CRational & operator/=(CRational const& r);

private:
	int m_numerator;
	int m_denominator;

	void Assign(int numerator, int denominator);
	// Нормализует рациональное число
	void Normalize();
};

// Вычисляет наибольший общий делитель (greatest common denominator) чисел a и b
unsigned GCD(unsigned a, unsigned b);

// Вычисляет наименьшее общее кратное (least common multiple) чисел a и b
unsigned LCM(unsigned a, unsigned b);

// Возвращает результат сложения двух рациональных чисел, 
//	рационального числа с целым, целого числа с рациональным.
const CRational operator+(CRational const& r1, CRational const& r2);

// Возвращает разность двух рациональных чисел, 
//	рационального числа и целого, либо целого числа и рационального:
const CRational operator-(CRational const& r1, CRational const& r2);

// Возвращает результат произведения рациональных чисел, 
//	рационального и целого, либо целого и рационального :
const CRational operator*(CRational const& r1, CRational const& r2);

// Возвращает частное двух рациональных чисел, 
//	рационального и целого, целого и рационального :
const CRational operator/(CRational const& r1, CRational const& r2);

// Сравнивают два рациональных числа, рациональное с целым, 
//	целое с рациональным:
const bool operator<(CRational const& r1, CRational const& r2);
const bool operator>(CRational const& r1, CRational const& r2);
const bool operator<=(CRational const& r1, CRational const& r2);
const bool operator>=(CRational const& r1, CRational const& r2);

// Проверяют равенство (и неравенство) двух рациональных чисел, 
//	целого и рационального, рационального и целого:
const bool operator != (CRational const& r1, CRational const& r2);
const bool operator == (CRational const& r1, CRational const& r2);

// Вывод рационального числа в выходной поток 
//	std::ostream в формате <числитель>/<знаменатель>, 
std::ostream & operator<<(std::ostream & out, const CRational & r);

// Ввод рационального числа из входного потока 
bool operator >> (std::istream & in, CRational & r);