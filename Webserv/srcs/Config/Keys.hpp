#ifndef KEYS_HPP
# define KEYS_HPP

# include "string"
# include "vector"
# include "../Parser/Directive.hpp"
# include "DataContainers.hpp"


#ifndef PARSER_UNDEFINED_MAX_TOKENS
# define PARSER_UNDEFINED_MAX_TOKENS (-1)
#endif


namespace Parser
{
	namespace Keys
	{
		class ServerName: public Parser::Directive
		{
		public:
			ServerName();
			~ServerName();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
		};

		class Ip: public Parser::Directive
		{
		public:
			Ip();
			~Ip();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
		};

		class Ports: public Parser::Directive
		{
		public:
			Ports();
			~Ports();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
		};

		class Root: public Parser::Directive
		{
		public:
			Root();
			~Root();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
		};

		class MaxBody: public Parser::Directive
		{
		public:
			MaxBody();
			~MaxBody();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);

		private:
			size_t	m_max_bytes;
		};

		class LocationPath: public Parser::Directive
		{
		public:
			LocationPath();
			~LocationPath();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
		};

		class Index: public Parser::Directive
		{
		public:
			Index();
			~Index();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
		};

		class AcceptMethod: public Parser::Directive
		{
		public:
			AcceptMethod();
			~AcceptMethod();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
			const 	std::vector<std::string> &get_valid_methods();
			bool 	is_in_methods(const std::string &method);
		};

		class ErrorPage: public Parser::Directive
		{
		public:
			ErrorPage();
			~ErrorPage();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
			const 	std::vector<std::string> &get_valid_pages();
			bool 	is_valid_page(const string &method);
		};

		class Redirection: public Parser::Directive
		{
		public:
			Redirection();
			~Redirection();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
		};

		class Autoindex: public Parser::Directive
		{
		public:
			Autoindex();
			~Autoindex();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
		};

		class UploadPath: public Parser::Directive
		{
		public:
			UploadPath();
			~UploadPath();

		private:
			void	m_validate_token(const std::string &token);
			void	m_format_checker(const std::vector<std::string> &tokens);
			void	m_save(const std::vector<std::string> &tokens, Data::Conf *config);
		};
	}
}

#endif
