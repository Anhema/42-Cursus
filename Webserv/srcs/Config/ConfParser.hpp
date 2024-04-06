#ifndef CONF_PARSER_HPP
# define CONF_PARSER_HPP

# include "../Parser/Parser.hpp"

namespace WebServ
{
	class ConfParser: public Parser::Reader
	{
	public:
		ConfParser(std::string const &file);
		~ConfParser();

		void	init();
		void	start();
        void    save(Data::Conf *data);
        void    print() const;
		void	add_context(Data::Server &context, Data::Location &location);
		void	validate();

        std::vector<Data::Server>	getBrackets() const;
    private:
        std::vector<Data::Server>	m_serverBrackets;
        int                       	m_serverBracket_count;
		int                       	m_locationBracket_count;

		void	validate_server(Data::Server &bracket);
		void	validate_location(Data::Location &bracket);
	};
}
#endif

