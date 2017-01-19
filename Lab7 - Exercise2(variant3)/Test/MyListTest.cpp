#include "stdafx.h"
#include "..\Lab7-Exercise2Variant3\MyList.h"

struct StringListFixture
{
	CMyList<std::string> myStringList;
	std::vector<std::string> stringVector = { "First", "Second", "Third", "Fourth", "Fifth" };
};

struct IntListFixture
{
	CMyList<int> myIntList;
	std::vector<int> intVector = { 1, 2, 3, 4, 5 };
};

BOOST_FIXTURE_TEST_SUITE(CMyStringList_class, StringListFixture)

	BOOST_AUTO_TEST_SUITE(by_default)

BOOST_AUTO_TEST_CASE(size_is_zero)
{
	BOOST_CHECK_EQUAL(myStringList.GetSize(), 0);
}

BOOST_AUTO_TEST_CASE(is_empty)
{
	BOOST_CHECK(myStringList.IsEmpty());
}

BOOST_AUTO_TEST_CASE(begin_is_nullptr_iterator)
{
	BOOST_CHECK(myStringList.begin() == CListIterator<std::string>(nullptr, false));
}

BOOST_AUTO_TEST_CASE(end_is_nullptr_iterator)
{
	BOOST_CHECK(myStringList.end() == CListIterator<std::string>(nullptr, false));
}

BOOST_AUTO_TEST_CASE(reversed_begin_is_nullptr_iterator)
{
	BOOST_CHECK(myStringList.rbegin() == CListIterator<std::string>(nullptr, true));
}

BOOST_AUTO_TEST_CASE(reversed_end_is_nullptr_iterator)
{
	BOOST_CHECK(myStringList.rend() == CListIterator<std::string>(nullptr, true));
}

BOOST_AUTO_TEST_CASE(cbegin_is_nullptr_iterator)
{
	BOOST_CHECK(myStringList.cbegin() == CListIterator<std::string>(nullptr, false));
}

BOOST_AUTO_TEST_CASE(cend_is_nullptr_iterator)
{
	BOOST_CHECK(myStringList.cend() == CListIterator<std::string>(nullptr, false));

}
BOOST_AUTO_TEST_CASE(crbegin_is_nullptr_iterator)
{
	BOOST_CHECK(myStringList.crbegin() == CListIterator<std::string>(nullptr, true));
}
BOOST_AUTO_TEST_CASE(crend_is_nullptr_iterator)
{
	BOOST_CHECK(myStringList.crend() == CListIterator<std::string>(nullptr, true));

}
BOOST_AUTO_TEST_CASE(cant_get_first_element_if_string_list_is_empty)
{
	BOOST_CHECK_THROW(myStringList.GetFirstElement(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(cant_get_last_element_if_string_list_is_empty)
{
	BOOST_CHECK_THROW(myStringList.GetLastElement(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(push_changes_size)
{
	myStringList.PushFront(std::string("First"));
	BOOST_CHECK_EQUAL(myStringList.GetSize(), 1);

	myStringList.PushBack(std::string("Second"));
	BOOST_CHECK_EQUAL(myStringList.GetSize(), 2);
}

BOOST_AUTO_TEST_CASE(can_get_first_element)
{
	for (size_t i = 0; i < stringVector.size(); ++i)
	{
		myStringList.PushBack(stringVector[i]);
	}

	std::string firstElement = myStringList.GetFirstElement();
	BOOST_CHECK_EQUAL(firstElement, stringVector.front());
}

BOOST_AUTO_TEST_CASE(can_get_last_element)
{
	for (size_t i = 0; i < stringVector.size(); ++i)
	{
		myStringList.PushBack(stringVector[i]);
	}

	std::string lastElement = myStringList.GetLastElement();
	BOOST_CHECK_EQUAL(lastElement, stringVector.back());
}

BOOST_AUTO_TEST_CASE(can_be_cleared)
{
	myStringList.PushBack(std::string("0"));
	myStringList.PushBack(std::string("1"));
	myStringList.Clear();
	BOOST_CHECK_EQUAL(myStringList.GetSize(), 0);
}

BOOST_AUTO_TEST_CASE(will_be_empty_after_destructor)
{
	myStringList.PushBack(std::string("0"));
	myStringList.PushBack(std::string("1"));
	myStringList.~CMyList();
	BOOST_CHECK_EQUAL(myStringList.GetSize(), 0);
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()


///////////////////CMyIntList//////////////////////////
BOOST_FIXTURE_TEST_SUITE(CMyIntList_class, IntListFixture)

BOOST_AUTO_TEST_SUITE(by_default_two)

BOOST_AUTO_TEST_CASE(size_is_zero)
{
	BOOST_CHECK_EQUAL(myIntList.GetSize(), 0);
}

BOOST_AUTO_TEST_CASE(is_empty)
{
	BOOST_CHECK(myIntList.IsEmpty());
}

BOOST_AUTO_TEST_CASE(begin_is_nullptr_iterator)
{
	BOOST_CHECK(myIntList.begin() == CListIterator<int>(nullptr, false));
}

BOOST_AUTO_TEST_CASE(end_is_nullptr_iterator)
{
	BOOST_CHECK(myIntList.end() == CListIterator<int>(nullptr, false));
}

BOOST_AUTO_TEST_CASE(reversed_begin_is_nullptr_iterator)
{
	BOOST_CHECK(myIntList.rbegin() == CListIterator<int>(nullptr, true));
}

BOOST_AUTO_TEST_CASE(reversed_end_is_nullptr_iterator)
{
	BOOST_CHECK(myIntList.rend() == CListIterator<int>(nullptr, true));
}

BOOST_AUTO_TEST_CASE(cbegin_is_nullptr_iterator)
{
	BOOST_CHECK(myIntList.cbegin() == CListIterator<int>(nullptr, false));
}

BOOST_AUTO_TEST_CASE(cend_is_nullptr_iterator)
{
	BOOST_CHECK(myIntList.cend() == CListIterator<int>(nullptr, false));

}

BOOST_AUTO_TEST_CASE(crbegin_is_nullptr_iterator)
{
	BOOST_CHECK(myIntList.crbegin() == CListIterator<int>(nullptr, true));
}

BOOST_AUTO_TEST_CASE(crend_is_nullptr_iterator)
{
	BOOST_CHECK(myIntList.crend() == CListIterator<int>(nullptr, true));
}

BOOST_AUTO_TEST_CASE(cant_get_first_element_if_string_list_is_empty)
{
	BOOST_CHECK_THROW(myIntList.GetFirstElement(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(cant_get_last_element_if_string_list_is_empty)
{
	BOOST_CHECK_THROW(myIntList.GetLastElement(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(push_changes_size)
{
	 int one = 1;
	 int two = 2;

	myIntList.PushFront(one);
	BOOST_CHECK_EQUAL(myIntList.GetSize(), 1);

	myIntList.PushBack(two);
	BOOST_CHECK_EQUAL(myIntList.GetSize(), 2);
}

BOOST_AUTO_TEST_CASE(can_get_first_element)
{
	for (size_t i = 0; i < intVector.size(); ++i)
	{
		myIntList.PushBack(intVector[i]);
	}

	int firstElement = myIntList.GetFirstElement();
	BOOST_CHECK_EQUAL(firstElement, intVector.front());
}

BOOST_AUTO_TEST_CASE(can_get_last_element)
{
	for (size_t i = 0; i < intVector.size(); ++i)
	{
		myIntList.PushBack(intVector[i]);
	}

	int lastElement = myIntList.GetLastElement();
	BOOST_CHECK_EQUAL(lastElement, intVector.back());
}

BOOST_AUTO_TEST_CASE(can_be_cleared)
{
	int zero = 0;
	int one = 1;

	myIntList.PushBack(zero);
	myIntList.PushBack(one);
	myIntList.Clear();
	BOOST_CHECK_EQUAL(myIntList.GetSize(), 0);
}

BOOST_AUTO_TEST_CASE(will_be_empty_after_destructor)
{
	int zero = 0;
	int one = 1;

	myIntList.PushBack(zero);
	myIntList.PushBack(one);
	myIntList.~CMyList();
	BOOST_CHECK_EQUAL(myIntList.GetSize(), 0);
}
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()