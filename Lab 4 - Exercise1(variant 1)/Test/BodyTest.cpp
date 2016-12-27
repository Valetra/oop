#include "stdafx.h"
#include "../Lab 4 - Exercise1(variant 1)/Sphere.h"
#include "../Lab 4 - Exercise1(variant 1)/Parallelepiped.h"
#include "../Lab 4 - Exercise1(variant 1)/Cone.h"
#include "../Lab 4 - Exercise1(variant 1)/Cylinder.h"

BOOST_AUTO_TEST_SUITE(Test_the_correct_operation_of_CBody_s_children)

////////////////CSphere///////////////////
//Проверка CSphere с нулевыми аргументами
BOOST_AUTO_TEST_CASE(Check_CSphere_with_zeroes_arguments)
{
	CSphere sphere(0,0);
	BOOST_CHECK(sphere.GetDensity() == 0);
	BOOST_CHECK(sphere.GetRadius() == 0);

	BOOST_CHECK(sphere.GetDensity() != 5);
	BOOST_CHECK(sphere.GetRadius() != 5);

	BOOST_CHECK(sphere.GetMass() == 0);
}

//Проверка CSphere с положительными аргументами
BOOST_AUTO_TEST_CASE(Check_CSphere_with_positive_arguments)
{
	double DENSITY = 1.5;
	double RADIUS = 5.0;
	CSphere sphere(DENSITY, RADIUS);
	BOOST_CHECK(sphere.GetDensity() == 1.5);
	BOOST_CHECK((sphere.GetVolume()) == (pow(RADIUS, 3) * M_PI) * 4 / 3);
	BOOST_CHECK(sphere.GetMass() == ((pow(RADIUS, 3) * M_PI) * 4 / 3) * DENSITY);
}

//Проверка CSphere на невозможность создания с отрицательными аргументами
BOOST_AUTO_TEST_CASE(Check_CSphere_can_not_create_sphere_with_negative_arguments)
{
	BOOST_CHECK_THROW(CSphere sphere(-20, -1), std::invalid_argument);
}

//Проверка CSphere на невозможность создания с отрицательным и положительным аргументами
BOOST_AUTO_TEST_CASE(Check_CSphere_can_not_create_sphere_with_negative_and_positive_arguments)
{
	BOOST_CHECK_THROW(CSphere sphere(-5, 4), std::invalid_argument);
}

//Проверка CSphere на вывод информации
BOOST_AUTO_TEST_CASE(Check_method_of_CBody_ToString)
{
	CSphere sphere(1, 1);
	BOOST_CHECK_EQUAL(sphere.ToString(), "\n\tDensity of body is: 1.000000\n\tVolume of body is: 4.188790\n\tMass of body is: 4.188790\n");
}


////////////////CParalelepiped///////////////////

//Проверка CParalelepiped на невозможность создания с отрицательными и положительными аргументами
BOOST_AUTO_TEST_CASE(Check_CParalelepiped_can_not_create_paralelepiped_with_negative_and_positive_arguments)
{
	BOOST_CHECK_THROW(CParallelepiped parallelepiped(-5, 1, -34, 56), std::invalid_argument);
}

//Проверка CParalelepiped с не отрицательными аргументами
BOOST_AUTO_TEST_CASE(Check_CParalelepiped_with_not_negative_arguments)
{
	CParallelepiped parallelepiped(5, 1, 2, 3);

	BOOST_CHECK(parallelepiped.GetDensity() == 5);
	BOOST_CHECK(parallelepiped.GetWidth() == 1);
	BOOST_CHECK(parallelepiped.GetHeight() == 2);
	BOOST_CHECK(parallelepiped.GetDepth() == 3);

	BOOST_CHECK(parallelepiped.GetVolume() == parallelepiped.GetDepth() * parallelepiped.GetWidth() * parallelepiped.GetHeight());
	BOOST_CHECK(parallelepiped.GetMass() == parallelepiped.GetVolume() * parallelepiped.GetDensity());
}

///////////////////CCone////////////////////////

//Проверка CCone на невозможность создания с отрицательными и положительными аргументами
BOOST_AUTO_TEST_CASE(Check_CCone_can_not_create_cone_with_negative_and_positive_arguments)
{
	BOOST_CHECK_THROW(CCone cone(2, -4, 1), std::invalid_argument);
}

//Проверка CCone с не отрицательными аргументами
BOOST_AUTO_TEST_CASE(Check_CCone_with_not_negative_arguments)
{
	CCone cone(2, 5, 10);

	BOOST_CHECK(cone.GetDensity() == 2);
	BOOST_CHECK(cone.GetHeight() == 5);
	BOOST_CHECK(cone.GetRadius() == 10);

	BOOST_CHECK(cone.GetVolume() == (1.0f / 3.0f) * M_PI * pow(cone.GetRadius(), 2) * cone.GetHeight());
	BOOST_CHECK(cone.GetMass() == cone.GetVolume() * cone.GetDensity());
}

////////////CCylinder////////////////////

//Проверка CCylinder на невозможность создания с отрицательными и положительными аргументами
BOOST_AUTO_TEST_CASE(Check_CCylinder_can_not_create_cone_with_negative_and_positive_arguments)
{
	BOOST_CHECK_THROW(CCylinder сylinder(-4, -2, 20), std::invalid_argument);
}

//Проверка CCylinder с не отрицательными аргументами
BOOST_AUTO_TEST_CASE(Check_CCylinder_with_not_negative_arguments)
{
	CCylinder cylinder(54, 2, 5);

	BOOST_CHECK(cylinder.GetDensity() == 54);
	BOOST_CHECK(cylinder.GetHeight() == 2);
	BOOST_CHECK(cylinder.GetRadius() == 5);

	BOOST_CHECK(cylinder.GetVolume() == M_PI * pow(cylinder.GetRadius(), 2) * cylinder.GetHeight());
	BOOST_CHECK(cylinder.GetMass() == cylinder.GetVolume() * cylinder.GetDensity());
}

BOOST_AUTO_TEST_SUITE_END();