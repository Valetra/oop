#include "HttpUrl.h"

CHttpUrl::CHttpUrl(std::string const& url)
{
	if (url.empty())
	{
		throw std::invalid_argument("Input is empty");
	}
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol = Protocol::HTTP,
	unsigned short port = 80)
	: m_protocol(protocol)
	, m_domain(domain)
	, m_port(port)
{
	if (domain.empty())
	{
		throw std::invalid_argument("Invalid domain");
	}
	m_document = (document.empty() || document[0] != '/') ? "/" + document : document;
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol)
	: m_protocol(protocol)
	, m_domain(domain)
{
	if (domain.empty())
	{
		throw std::invalid_argument("Invalid domain");
	}
	m_document = (document.empty() || document[0] != '/') ? "/" + document : document;
	m_port = GetDefaultPort(m_protocol);
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document)
	: m_protocol(HTTP)
	, m_domain(domain)
{
	if (domain.empty())
	{
		throw std::invalid_argument("Invalid domain");
	}
	m_document = (document.empty() || document[0] != '/') ? "/" + document : document;
	m_port = GetDefaultPort(m_protocol);
}

std::string CHttpUrl::GetURL() const
{
	return ProtocolToString(m_protocol) + "://" + GetDomain() + m_document;
}

std::string CHttpUrl::GetDomain() const
{
	std::string result = m_domain;
	if (!(m_protocol == Protocol::HTTP && m_port == 80 || m_protocol == Protocol::HTTPS && m_port == 443))
	{
		result += ":" + std::to_string(m_port);
	}
	return result;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

void CHttpUrl::ParseUrl(std::string const& url)
{
	size_t startPos = 0;
	ParseProtocol(url, startPos);
	ParseDomain(url, startPos);
	ParsePort(url, startPos);
	ParseDocument(url, startPos);
}

void CHttpUrl::ParseProtocol(std::string const& url, size_t & pos)
{
	std::string protocol;
	for (pos; pos < url.length(); ++pos)
	{
		if (url[pos] == ':')
		{
			break;
		}
		protocol += url[pos];
	}

	m_protocol = StringToProtocol(protocol);
	if (url.length() <= pos + 2 || url[pos] != ':' || url[pos + 1] != '/' || url[pos + 2] != '/')
	{
		throw CUrlParsingError("Invalid protocol");
	}
	pos += 3;
}

void CHttpUrl::ParseDomain(std::string const& url, size_t & pos)
{
	for (pos; pos < url.length(); ++pos)
	{
		if (url[pos] == '/' || url[pos] == ':')
		{
			break;
		}
		m_domain += url[pos];
	}
	if (m_domain.empty())
	{
		throw CUrlParsingError("No domain specified");
	}
}

void CHttpUrl::ParsePort(std::string const& url, size_t & pos)
{
	if (url[pos] != ':')
	{
		m_port = GetDefaultPort(m_protocol);
		return;
	}
	if (url.length() <= pos + 1)
	{
		throw CUrlParsingError("Invalid port");
	}
	pos++;
	std::string port;
	for (pos; pos < url.length(); ++pos)
	{
		if (url[pos] == '/')
		{
			break;
		}
		port += url[pos];
	}
	if (port.empty())
	{
		throw CUrlParsingError("Invalid port");
	}
	try
	{
		boost::lexical_cast<unsigned short>(port);
	}
	catch (boost::bad_lexical_cast &)
	{
		throw CUrlParsingError("Invalid port");
	}
	m_port = atoi(port.c_str());
}

void CHttpUrl::ParseDocument(std::string const& url, size_t & pos)
{
	if (url[pos] == '/' && url.length() > pos + 1)
	{
		pos++;
	}
	for (pos; pos < url.length(); ++pos)
	{
		if (url[pos] == '/')
		{
			break;
		}
		m_document += url[pos];
	}
}

static unsigned short GetDefaultPort(Protocol const& protocol)
{
	if (protocol == Protocol::HTTPS)
	{
		return 443;
	}
	else
	{
		return 80;
	}
}

static std::string ProtocolToString(Protocol const& protocol)
{
	if (protocol == Protocol::HTTP)
	{
		return "http";
	}
	else if (protocol == Protocol::HTTPS)
	{
		return "https";
	}
	else
	{
		throw std::invalid_argument("Invalid protocol");
	}
}

static Protocol StringToProtocol(std::string protocol)
{
	if (protocol == "http")
	{
		return Protocol::HTTP;
	}
	else if (protocol == "https")
	{
		return Protocol::HTTPS;
	}
	else
	{
		throw CUrlParsingError("Invalid protocol");
	}
}