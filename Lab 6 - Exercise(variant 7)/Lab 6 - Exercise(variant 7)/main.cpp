#include "stdafx.h"
#include "HttpUrl.h"

using namespace std;

std::string ProtocolToString(Protocol const& protocol)
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

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		try
		{
			CHttpUrl httpUrl(line);
			cout << "Url: " << httpUrl.GetURL() << "\n"
				<< "Protocol: " << ProtocolToString(httpUrl.GetProtocol()) << "\n"
				<< "Domain: " << httpUrl.GetDomain() << "\n"
				<< "Document: " << httpUrl.GetDocument() << "\n"
				<< "Port: " << httpUrl.GetPort() << "\n";
		}
		catch (std::invalid_argument &e)
		{
			cout << e.what() << "\n";
		}
	}
	return 0;
}