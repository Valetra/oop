#include "stdafx.h"
#include "../Lab 6 - Exercise(variant 7)/HttpUrl.h"

void VerifyUrl(CHttpUrl const& httpUrl,
	std::string const& url,
	Protocol const& protocol,
	std::string const& domain,
	std::string const& document,
	unsigned short port)
{
	BOOST_CHECK_EQUAL(httpUrl.GetURL(), url);
	BOOST_CHECK_EQUAL(httpUrl.GetProtocol(), protocol);
	BOOST_CHECK_EQUAL(httpUrl.GetDomain(), domain);
	BOOST_CHECK_EQUAL(httpUrl.GetDocument(), document);
	BOOST_CHECK_EQUAL(httpUrl.GetPort(), port);
}

struct HttpUrlFixture
{
	CHttpUrl httpUrl;
	HttpUrlFixture()
		: httpUrl("http://google.com/index.php")
	{

	}
};

BOOST_FIXTURE_TEST_SUITE(CHttpUrl_class, HttpUrlFixture)

BOOST_AUTO_TEST_CASE(can_get_url)
{
	BOOST_CHECK_EQUAL(httpUrl.GetURL(), "http://google.com/index.php");
}
BOOST_AUTO_TEST_CASE(can_get_protocol)
{
	BOOST_CHECK_EQUAL(httpUrl.GetProtocol(), HTTP);
}
BOOST_AUTO_TEST_CASE(can_get_domain)
{
	BOOST_CHECK_EQUAL(httpUrl.GetDomain(), "google.com");
}
BOOST_AUTO_TEST_CASE(can_get_document)
{
	BOOST_CHECK_EQUAL(httpUrl.GetDocument(), "/index.php");
}
BOOST_AUTO_TEST_CASE(can_get_port)
{
	BOOST_CHECK_EQUAL(httpUrl.GetPort(), 80);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CHttpUrl_class_can_be_initialized)

BOOST_AUTO_TEST_CASE(directly)
{
	CHttpUrl httpUrl("google.com", "index.php", HTTP, 80);
	VerifyUrl(httpUrl, "http://google.com/index.php", HTTP, "google.com", "/index.php", 80);
}

BOOST_AUTO_TEST_CASE(without_port)
{
	{
		CHttpUrl httpUrl("google.com", "index.php", HTTP);
		VerifyUrl(httpUrl, "http://google.com/index.php", HTTP, "google.com", "/index.php", 80);
	}
	{
		CHttpUrl httpUrl("google.com", "index.php", HTTPS);
		VerifyUrl(httpUrl, "https://google.com/index.php", HTTPS, "google.com", "/index.php", 443);
	}
}

BOOST_AUTO_TEST_CASE(without_port_and_protocol)
{
	CHttpUrl httpUrl("google.com", "index.php");
	VerifyUrl(httpUrl, "http://google.com/index.php", HTTP, "google.com", "/index.php", 80);
}

BOOST_AUTO_TEST_CASE(with_single_string)
{
	{
		CHttpUrl httpUrl("http://google.com");
		VerifyUrl(httpUrl, "http://google.com/", HTTP, "google.com", "/", 80);
	}
	{
		CHttpUrl httpUrl("https://google.com");
		VerifyUrl(httpUrl, "https://google.com/", HTTPS, "google.com", "/", 443);
	}
	{
		CHttpUrl httpUrl("http://google.com/");
		VerifyUrl(httpUrl, "http://google.com/", HTTP, "google.com", "/", 80);
	}
	{
		CHttpUrl httpUrl("https://google.com:465/");
		VerifyUrl(httpUrl, "https://google.com:465/", HTTPS, "google.com:465", "/", 465);
	}
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CHttpUrl_class_cant_be_initialized_with_single_string_if)

BOOST_AUTO_TEST_CASE(input_is_empty)
{
	BOOST_CHECK_THROW(CHttpUrl httpUrl(""), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(port_is_overflow)
{
	BOOST_CHECK_THROW(CHttpUrl httpUrl("http://google.com:65536"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(has_wrong_protocol)
{
	BOOST_CHECK_THROW(CHttpUrl httpUrl("google.com"), CUrlParsingError);
	BOOST_CHECK_THROW(CHttpUrl httpUrl("httpr://google.com"), CUrlParsingError);
	BOOST_CHECK_THROW(CHttpUrl httpUrl("http:/google.com"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(has_not_domain)
{
	BOOST_CHECK_THROW(CHttpUrl httpUrl("http://"), CUrlParsingError);
	BOOST_CHECK_THROW(CHttpUrl httpUrl("http:///index.php"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(has_wrong_port)
{
	BOOST_CHECK_THROW(CHttpUrl httpUrl("http://google.com:"), CUrlParsingError);
	BOOST_CHECK_THROW(CHttpUrl httpUrl("http://google.com:/"), CUrlParsingError);
	BOOST_CHECK_THROW(CHttpUrl httpUrl("http://google.com:asd"), CUrlParsingError);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CHttpUrl_class)

BOOST_AUTO_TEST_CASE(cant_be_initialized_directly_if_has_empty_domain)
{
	BOOST_CHECK_THROW(CHttpUrl httpUrl("", "index.php", HTTP, 80), std::invalid_argument);
	BOOST_CHECK_THROW(CHttpUrl httpUrl("", "index.php", HTTP), std::invalid_argument);
	BOOST_CHECK_THROW(CHttpUrl httpUrl("", "index.php"), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(cant_get_url_with_wrong_protocol)
{
	CHttpUrl httpUrl("google.com", "index.php", static_cast<Protocol>(30), 80);
	BOOST_CHECK_THROW(httpUrl.GetURL(), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()