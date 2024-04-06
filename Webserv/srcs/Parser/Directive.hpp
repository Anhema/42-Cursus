#ifndef DIRECTIVE_HPP
# define DIRECTIVE_HPP

#ifndef __WEBSERV_UNDEFINED_MAX_TOKENS
#endif

# include "Utilities.hpp"
# include "DataContainers.hpp"
# include <string>
# include <vector>


namespace Parser
{
	enum Errors
	{
		NO_ERROR,
		TOO_MANY_ARGUMENTS,
		INVALID_VALUE,
		INVALID_TOKEN
	};

	class Directive
	{
	protected:
		const std::string				m_keyword;
		const short 					m_max_tokens;	// Intialize to -1 for undefined
		std::string						m_err_token;
		Parser::Errors					m_errno;


	public:
		Directive(const std::string &keyword, short max_tokens);
		virtual ~Directive();

		template<class T>
		static Parser::Directive	*KeyFactory()
		{
			return new T;
		}

		Parser::Errors		Error() const;
		void				Throw(const std::string &line);
		void 				handler(const std::vector<std::string> &tokens, Data::Conf *dst);
		bool 				asciiCheck(const std::string &token);
		bool				std_max_tokens_check(const std::vector<std::string> &tokens);

	private:
		void				m_iterate_through(const std::vector<std::string> &tokens);

	protected:
		virtual void		m_validate_token(const std::string &token) = 0;
		virtual void		m_format_checker(const std::vector<std::string> &tokens) = 0;
		virtual void 		m_save(const std::vector<std::string> &tokens, Data::Conf *dst) = 0;
	};
}

#endif
