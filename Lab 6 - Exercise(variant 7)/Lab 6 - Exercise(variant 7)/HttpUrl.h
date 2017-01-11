#pragma once
#include "stdafx.h"
#include "UrlParsingError.h"

/*

1. ќставить один конструктор из трех, но с поддержкой вызова с 2 аргументами
2. »збавитьс€ от дублировани€ литеральных констант
3. »спользовать регул€рные выражени€
4. ќчень странно парситс€ "документ". (пример: http://ya.ru/d/ddddddd)

*/

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	~CHttpUrl() = default;

	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol,
		unsigned short port);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol);
	CHttpUrl(
		std::string const& domain,
		std::string const& document);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;
private:
	void ParseUrl(std::string const& url);
	void ParseProtocol(std::string const& url, size_t & pos);
	void ParseDomain(std::string const& url, size_t & pos);
	void ParsePort(std::string const& url, size_t & pos);
	void ParseDocument(std::string const& url, size_t & pos);
	std::string m_domain;
	std::string m_document = "/";
	Protocol m_protocol = HTTP;
	unsigned short m_port = 80;
};

static unsigned short GetDefaultPort(Protocol const& protocol);
static std::string ProtocolToString(Protocol const& protocol);
static Protocol StringToProtocol(std::string protocol);