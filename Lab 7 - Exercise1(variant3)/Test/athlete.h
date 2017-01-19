#pragma once
#include "stdafx.h"

struct Athlete
{
	std::string fullName;
	double height;
	double weight;
};

bool IsLessWeight(Athlete const& lhs, Athlete const& rhs)
{
	return (lhs.weight < rhs.weight);
}

bool IsLessHeight(Athlete const& lhs, Athlete const& rhs)
{
	return (lhs.height < rhs.height);
}

void AreEquals(Athlete const& lhs, Athlete const& rhs)
{
	BOOST_CHECK_EQUAL(lhs.fullName, rhs.fullName);
	BOOST_CHECK_EQUAL(lhs.height, rhs.height);
	BOOST_CHECK_EQUAL(lhs.weight, rhs.weight);
}