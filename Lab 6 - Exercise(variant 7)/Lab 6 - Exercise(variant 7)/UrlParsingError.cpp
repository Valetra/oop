#include "UrlParsingError.h"

CUrlParsingError::CUrlParsingError(std::string message)
	: std::invalid_argument(message)
{
}