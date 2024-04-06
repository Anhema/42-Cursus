#include "Directive.hpp"
#include "Parser.hpp"

Parser::Directive::Directive(const std::string &keyword, const short max_tokens): m_keyword(keyword), m_max_tokens(max_tokens), m_errno(NO_ERROR)
{
	//cout << "Directive Constructed\n";
}

Parser::Directive::~Directive()
{
	//cout << "Directive Destructed\n";
}


void Parser::Directive::m_iterate_through(const std::vector <std::string> &tokens)
{
	for (std::vector<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); it++)
	{
		this->m_validate_token(*it);
		if (this->m_errno)
			return;
	}
}

void Parser::Directive::handler(const std::vector <std::string> &tokens, Data::Conf *dst)
{
	this->m_format_checker(tokens);
	this->m_iterate_through(tokens);
	this->m_save(tokens, dst);
}

Parser::Errors Parser::Directive::Error() const
{
	return this->m_errno;
}

void Parser::Directive::Throw(const std::string &line)
{
	switch (this->m_errno)
	{
		case NO_ERROR:
			break;
		case TOO_MANY_ARGUMENTS:
			break;
		case INVALID_VALUE:
			throw (Parser::InvalidValue(line, this->m_err_token, 10));
		case INVALID_TOKEN:
			break;
	}
}

bool Parser::Directive::asciiCheck(const string &token) {

	for (std::string::const_iterator it = token.begin(); it != token.end(); it++)
	{
		if (!isascii(*it))
		{
			this->m_err_token = token;
			this->m_errno = INVALID_VALUE;
			return false;
		}
	}
	return true;
}

bool Parser::Directive::std_max_tokens_check(const std::vector<std::string> &tokens) {
	if (this->m_max_tokens != PARSER_UNDEFINED_MAX_TOKENS && static_cast<short>(tokens.size()) > this->m_max_tokens)
	{
		this->m_errno = TOO_MANY_ARGUMENTS;
		return false;
	}
	return true;
}
