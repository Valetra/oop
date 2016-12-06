#include "stdafx.h"
#include "../Lab 5 - Exercise1(variant 3)/Rational.h"

BOOST_AUTO_TEST_CASE(Test_Greates_Common_Denominator)
{
	BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
	BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
	BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
	BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
	BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
	BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}

BOOST_AUTO_TEST_CASE(Test_Least_Common_Multiple)
{
	BOOST_CHECK_EQUAL(LCM(2, 3), 6u);
	BOOST_CHECK_EQUAL(LCM(3, 2), 6u);
	BOOST_CHECK_EQUAL(LCM(12, 8), 24u);
	BOOST_CHECK_EQUAL(LCM(8, 12), 24u);
	BOOST_CHECK_EQUAL(LCM(0, 2), 0u);
	BOOST_CHECK_EQUAL(LCM(2, 0), 0u);
	BOOST_CHECK_EQUAL(LCM(0, 0), 0u);
}

/*
Рациональное число:
равно нулю по умолчанию (0/1)
может быть созданно из целого в формате (n / 1)
может быть задано с указанием числителя и знаменателя
хранится в нормализованном виде
*/

void VerifyRational(CRational const& r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational_number)

BOOST_AUTO_TEST_CASE(is_0_by_default)
{
	VerifyRational(CRational(), 0, 1);
}
BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
{
	VerifyRational(CRational(5), 5, 1);
	VerifyRational(CRational(-5), -5, 1);
	VerifyRational(CRational(0), 0, 1);
}
BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
{
	VerifyRational(CRational(5, 2), 5, 2);
	VerifyRational(CRational(-5, 2), -5, 2);
	VerifyRational(CRational(5, -2), -5, 2);
	VerifyRational(CRational(-5, -2), 5, 2);
}
BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
{
	VerifyRational(CRational(4, 8), 1, 2);
	VerifyRational(CRational(4, -8), -1, 2);
	VerifyRational(CRational(-4, 8), -1, 2);
	VerifyRational(CRational(-4, -8), 1, 2);
	VerifyRational(CRational(-10, 20), -1, 2);
}
BOOST_AUTO_TEST_CASE(cant_have_zero_denominator)
{
	BOOST_REQUIRE_THROW(CRational(1, 0), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(can_be_converted_to_double)
{
	BOOST_CHECK_CLOSE_FRACTION(CRational(3, 5).ToDouble(), 0.6, DBL_EPSILON);
}
BOOST_AUTO_TEST_CASE(unary_plus_returns_source_rational)
{
	VerifyRational(+CRational(1, 2), 1, 2);
	VerifyRational(+CRational(0, 5), 0, 1);
}
BOOST_AUTO_TEST_CASE(unary_minus_negates_rational)
{
	VerifyRational(-CRational(3, 5), -3, 5);
	VerifyRational(-CRational(-3, -5), -3, 5);
	VerifyRational(-CRational(3, -5), 3, 5);
	VerifyRational(-CRational(-3, 5), 3, 5);

	const CRational r1(-2, 1);
	CRational r2 = -r1;
	VerifyRational(r2, 2, 1);
}
BOOST_AUTO_TEST_CASE(has_binary_addition_operation)
{
	VerifyRational(CRational(1, 3) + CRational(1, 6), 1, 2);
	VerifyRational(CRational(1, 6) + CRational(1, 3), 1, 2);
	VerifyRational(CRational(1, 2) + CRational(1, 2), 1, 1);
	VerifyRational(CRational(1, 2) + 1, 3, 2);
	VerifyRational(1 + CRational(1, 2), 3, 2);
	VerifyRational(CRational(1, 3) + CRational(1, 3) + CRational(1, 3), 1, 1);
}
BOOST_AUTO_TEST_CASE(has_binary_subtraction_operation)
{
	VerifyRational(CRational(1, 2) - CRational(1, 4), 1, 4);
	VerifyRational(CRational(1, 4) - CRational(1, 2), -1, 4);
	VerifyRational(CRational(1, 2) - CRational(1, 2), 0, 1);
	VerifyRational(CRational(1, 2) - 1, -1, 2);
	VerifyRational(1 - CRational(1, 2), 1, 2);
	VerifyRational(CRational(1, 2) - CRational(1, 2) - CRational(1, 2), -1, 2);
}
BOOST_AUTO_TEST_CASE(has_adding_assignment_operator)
{
	CRational r(3, 23);
	VerifyRational(r += r, 6, 23);
	VerifyRational(r += r, 12, 23);
	VerifyRational(r += CRational(0, 2), 12, 23);

	VerifyRational(CRational(1, 2) += CRational(1, 4), 3, 4);
	VerifyRational(CRational(1, 2) += 1, 3, 2);
	VerifyRational(CRational(0, 2) += 1, 1, 1);
}
BOOST_AUTO_TEST_CASE(must_have_a_valid_addition_assignment)
{
	int x = 3, y = 5, z = 6;
	(x += y) += z;

	CRational rx(3);
	CRational ry(5);
	CRational rz(6);
	(rx += ry) += rz;
	BOOST_CHECK(rx == x);
}
BOOST_AUTO_TEST_CASE(has_subtracting_assignment_operator)
{
	CRational r(3, 23);
	VerifyRational(r -= r, 0, 1);

	CRational r2(3, 23);
	VerifyRational(r2 -= CRational(0, 1), 3, 23);

	VerifyRational(CRational(1, 2) -= CRational(1, 4), 1, 4);
	VerifyRational(CRational(1, 2) -= 1, -1, 2);
}
BOOST_AUTO_TEST_CASE(has_binary_multiplication_operation)
{
	VerifyRational(CRational(2, 3) * CRational(1, 2), 1, 3);
	VerifyRational(CRational(1, 2) * CRational(2, 3), 1, 3);
	VerifyRational(CRational(11, 4) * 0, 0, 1);
	VerifyRational(7 * CRational(2, 3), 14, 3);
	VerifyRational(CRational(1, 2) * (-3), -3, 2);
	VerifyRational(CRational(0, 1) * 0, 0, 1);
	VerifyRational(CRational(11, 4) * CRational(3, 2) * CRational(2, 5), 33, 20);
}
BOOST_AUTO_TEST_CASE(has_division_operation)
{
	VerifyRational(CRational(1, 2) / CRational(2, 3), 3, 4);
	VerifyRational(CRational(1, 2) / 4, 1, 8);
	VerifyRational(7 / CRational(2, 3), 21, 2);
	VerifyRational(0 / CRational(2, 3), 0, 1);
	BOOST_REQUIRE_THROW(CRational(2, 3) / 0, std::invalid_argument);
	BOOST_REQUIRE_THROW(CRational(2, 3) / CRational(0, 1), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(has_multiply_assignment_operator)
{
	CRational r(3, 2);
	VerifyRational(r *= r, 9, 4);
	VerifyRational(CRational(1, 2) *= CRational(2, 1), 1, 1);
	VerifyRational(CRational(3, 14) *= 7, 3, 2);
	VerifyRational(CRational(1, 2) *= 3, 3, 2);
}
BOOST_AUTO_TEST_CASE(has_division_assignment_operator)
{
	CRational r(2, 3);
	VerifyRational(r /= r, 1, 1);
	VerifyRational(CRational(1, 2) /= CRational(2, 3), 3, 4);
	VerifyRational(CRational(2, 3) /= CRational(2, 3), 1, 1);
	VerifyRational(CRational(1, 2) /= 2, 1, 4);
	BOOST_REQUIRE_THROW(CRational(1, 4) /= 0, std::invalid_argument);
	BOOST_REQUIRE_THROW(CRational(1, 4) /= CRational(0, 1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE(comparison_operators)

BOOST_AUTO_TEST_CASE(equality)
{
	BOOST_CHECK(CRational(1, 2) == CRational(1, 2));
	BOOST_CHECK(CRational(1, 3) == CRational(2, 6));
	BOOST_CHECK(3 == CRational(3, 1));
	BOOST_CHECK(CRational(4, 1) == 4);
	BOOST_CHECK(!(CRational(1, 2) == CRational(2, 3)));
	BOOST_CHECK(!(CRational(1, 2) == 1));
	BOOST_CHECK(!(3 == CRational(2, 3)));
}
BOOST_AUTO_TEST_CASE(not_equality)
{
	BOOST_CHECK(!(CRational(1, 2) != CRational(1, 2)));
	BOOST_CHECK(!(CRational(1, 3) != CRational(2, 6)));
	BOOST_CHECK(!(CRational(4, 1) != 4));
	BOOST_CHECK(!(3 != CRational(3, 1)));
	BOOST_CHECK(CRational(1, 2) != CRational(2, 3));
	BOOST_CHECK(CRational(1, 2) != 7);
	BOOST_CHECK(3 != CRational(2, 3));
}
BOOST_AUTO_TEST_CASE(less)
{
	BOOST_CHECK(CRational(1, 2) < 1);
	BOOST_CHECK(CRational(-1, 2) < 0);
	BOOST_CHECK(0 < CRational(1, 2));
	BOOST_CHECK(!(CRational(1, 2) < 0));
	BOOST_CHECK(!(CRational(1, 2) < CRational(1, 2)));
	BOOST_CHECK(CRational(1, 3) < CRational(1, 2));
	BOOST_CHECK(CRational(-1, 2) < CRational(1, 2));
}
BOOST_AUTO_TEST_CASE(greater)
{
	BOOST_CHECK(CRational(3, 1) > 2);
	BOOST_CHECK(CRational(3, 1) > 0);
	BOOST_CHECK(0 > CRational(-1, 2));
	BOOST_CHECK(!(CRational(-1, 2) > 0));
	BOOST_CHECK(CRational(1, 2) > CRational(-1, 2));
	BOOST_CHECK(!(CRational(1, 2) > CRational(1, 2)));
	BOOST_CHECK(!(CRational(1, 3) > CRational(1, 2)));
	BOOST_CHECK(!(CRational(-5, 2) > CRational(-2, 1)));
}
BOOST_AUTO_TEST_CASE(less_or_equal)
{
	BOOST_CHECK(3 <= CRational(7, 2));
	BOOST_CHECK(!(CRational(1, 2) <= CRational(1, 3)));
	BOOST_CHECK(CRational(3, 2) <= CRational(3, 2));
	BOOST_CHECK(CRational(3, 3) <= CRational(3, 2));
	BOOST_CHECK(CRational(1, 2) <= 1);
	BOOST_CHECK(0 <= CRational(1, 2));
	BOOST_CHECK(CRational(-1, 2) <= CRational(-1, 3));
}
BOOST_AUTO_TEST_CASE(greater_or_equal)
{
	BOOST_CHECK(CRational(1, 2) >= CRational(1, 3));
	BOOST_CHECK(!(3 >= CRational(8, 2)));
	BOOST_CHECK(CRational(1, 2) >= CRational(1, 3));
	BOOST_CHECK(CRational(1, 2) >= CRational(1, 2));
	BOOST_CHECK(CRational(1, 2) >= 0);
	BOOST_CHECK(1 >= CRational(1, 2));
	BOOST_CHECK(CRational(-1, 3) >= CRational(-1, 2));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(can_be_printed_to_ostream)
{
	boost::test_tools::output_test_stream output;
	output << CRational(7, 15);
	BOOST_CHECK(output.is_equal("7/15"));

	output.clear();
	output << "Rational number: " << CRational(-1, 2) << " in string";
	BOOST_CHECK(output.is_equal("Rational number: -1/2 in string"));

	output.clear();
	output << CRational(3);
	BOOST_CHECK(output.is_equal("3/1"));
}
BOOST_AUTO_TEST_CASE(can_be_initialized_from_istream)
{
	std::stringstream input("3/4");
	CRational r;
	input >> r;
	VerifyRational(r, 3, 4);
}
BOOST_AUTO_TEST_CASE(cant_be_initialized_from_wrong_istream)
{
	CRational r;
	std::stringstream input("");
	BOOST_CHECK_EQUAL(input.fail(), false);
	input >> r;
	BOOST_CHECK_EQUAL(input.fail(), true);

	input.clear();
	input.str("3s/4");
	BOOST_CHECK_EQUAL(input.fail(), false);
	BOOST_CHECK_THROW(input >> r, std::invalid_argument);
	BOOST_CHECK_EQUAL(input.fail(), true);

	input.clear();
	input.str("34");
	BOOST_CHECK_THROW(input >> r, std::invalid_argument);
	BOOST_CHECK_EQUAL(input.fail(), true);

	input.clear();
	input.str("3/4s");
	BOOST_CHECK_THROW(input >> r, std::invalid_argument);
	BOOST_CHECK_EQUAL(input.fail(), true);

	input.clear();
	input.str(std::to_string(INT_MAX) + "9/4");
	BOOST_CHECK_THROW(input >> r, std::out_of_range);
	BOOST_CHECK_EQUAL(input.fail(), true);

	input.clear();
	input.str("3/9" + std::to_string(INT_MAX));
	BOOST_CHECK_THROW(input >> r, std::out_of_range);
	BOOST_CHECK_EQUAL(input.fail(), true);
}



BOOST_AUTO_TEST_SUITE_END()