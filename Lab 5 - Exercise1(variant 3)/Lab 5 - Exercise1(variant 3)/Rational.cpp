#include "stdafx.h"
#include "Rational.h"

CRational::CRational(int numerator, int denominator)
{
	Assign(numerator, denominator);
}

void CRational::Assign(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	m_numerator = numerator;
	m_denominator = denominator;
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

unsigned LCM(unsigned a, unsigned b)
{
	return a / GCD(a, b) * b;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}

const CRational CRational::operator+() const
{
	return *this;
}

const CRational CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

const CRational operator+(CRational const& r1, CRational const& r2)
{
	int numerator = r1.GetNumerator() * r2.GetDenominator() + r2.GetNumerator() * r1.GetDenominator();
	int denominator = r1.GetDenominator() * r2.GetDenominator();
	return CRational(numerator, denominator);
}

const CRational operator-(CRational const& r1, CRational const& r2)
{
	int numerator = r1.GetNumerator() * r2.GetDenominator() - r2.GetNumerator() * r1.GetDenominator();
	int denominator = r1.GetDenominator() * r2.GetDenominator();
	return CRational(numerator, denominator);
}

CRational & CRational::operator+=(CRational const& r)
{
	if (r.GetNumerator() == 0)
	{
		return *this;
	}
	auto lcm = LCM(GetDenominator(), r.GetDenominator());
	Assign(GetNumerator() * (lcm / r.GetDenominator()) + r.GetNumerator() * (lcm / GetDenominator()), lcm);
	return *this;
}

CRational & CRational::operator-=(CRational const& r)
{
	if (r.GetNumerator() == 0)
	{
		return *this;
	}
	auto lcm = LCM(GetDenominator(), r.GetDenominator());
	Assign(r.GetNumerator() * (lcm / GetDenominator()) - GetNumerator() * (lcm / r.GetDenominator()), lcm);
	return *this;
}

const CRational operator*(CRational const& r1, CRational const& r2)
{
	return CRational(r1.GetNumerator() * r2.GetNumerator(), r1.GetDenominator() * r2.GetDenominator());
}

const CRational operator/(CRational const& r1, CRational const& r2)
{
	return CRational(r1.GetNumerator() * r2.GetDenominator(), r1.GetDenominator() * r2.GetNumerator());
}

CRational & CRational::operator*=(CRational const& r)
{
	Assign(m_numerator * r.GetNumerator(), m_denominator * r.GetDenominator());
	return *this;
}

CRational & CRational::operator/=(CRational const& r)
{
	Assign(m_numerator * r.GetDenominator(), m_denominator * r.GetNumerator());
	return *this;
}

const bool operator == (CRational const& r1, CRational const& r2)
{
	return (r1.GetNumerator() == r2.GetNumerator() && r1.GetDenominator() == r2.GetDenominator());
}

const bool operator != (CRational const& r1, CRational const& r2)
{
	return (r1.GetNumerator() != r2.GetNumerator() || r1.GetDenominator() != r2.GetDenominator());
}

const bool operator<(CRational const& r1, CRational const& r2)
{
	return (r1.GetNumerator() * r2.GetDenominator() < r2.GetNumerator() * r1.GetDenominator());
}

const bool operator>(CRational const& r1, CRational const& r2)
{
	return (r1.GetNumerator() * r2.GetDenominator() > r2.GetNumerator() * r1.GetDenominator());
}

const bool operator<=(CRational const& r1, CRational const& r2)
{
	return !(r1 > r2);
}

const bool operator>=(CRational const& r1, CRational const& r2)
{
	return !(r1 < r2);
}

std::ostream & operator<<(std::ostream & out, CRational const& r)
{
	out << r.GetNumerator() << '/' << r.GetDenominator();
	return out;
}

int GetNumeratorFromString(std::string const& rationalStr, size_t &startPos)
{
	std::string resultStr;
	bool doesDivisionFound = false;
	for (size_t i = 0; i < rationalStr.length(); ++i)
	{
		if (rationalStr[i] == '/')
		{
			startPos = i + 1;
			doesDivisionFound = true;
			break;
		}
		if (!isdigit(rationalStr[i]))
		{
			throw std::invalid_argument("Numerator contains not decimical symbol");
		}
		resultStr += rationalStr[i];
	}
	if (!doesDivisionFound)
	{
		throw std::invalid_argument("Division doesn't found");
	}

	try
	{
		return stoi(resultStr);
	}
	catch (std::out_of_range &)
	{
		throw std::out_of_range("Numerator is too big");
	}
}

int GetDenominatorFromString(std::string const& rationalStr, size_t startPos)
{
	std::string resultStr;
	for (size_t i = startPos; i < rationalStr.length(); ++i)
	{
		if (!isdigit(rationalStr[i]))
		{
			throw std::invalid_argument("Numerator contains not decimical symbol");
		}
		resultStr += rationalStr[i];
	}
	try
	{
		return stoi(resultStr);
	}
	catch (std::out_of_range &)
	{
		throw std::out_of_range("Denominator is too big");
	}
}

bool operator >> (std::istream & in, CRational & r)
{
	std::string rationalStr;
	int numerator = 0;
	int denominator = 0;
	if (in >> rationalStr)
	{
		try
		{
			size_t startPos = 0;
			numerator = GetNumeratorFromString(rationalStr, startPos);
			denominator = GetDenominatorFromString(rationalStr, startPos);
		}
		catch (...)
		{
			in.setstate(std::ios_base::failbit);
			throw;
		}
		r.SetNumerator(numerator);
		r.SetDenominator(denominator);
		return true;
	}
	else
	{
		in.setstate(std::ios_base::failbit);
	}
	return false;
}

void CRational::SetNumerator(int numerator)
{
	m_numerator = numerator;
}

void CRational::SetDenominator(int denominator)
{
	m_denominator = denominator;
}