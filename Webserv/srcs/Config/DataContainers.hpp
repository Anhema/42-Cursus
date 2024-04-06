#ifndef DATA_CONTAINERS_HPP
# define DATA_CONTAINERS_HPP

# include "string"
# include "vector"

namespace Data
{
	struct Server;

	struct  Conf
	{
		virtual void clear() = 0;
		virtual ~Conf();
	};
	struct	ErrorPages: Conf
	{
		ErrorPages();
		ErrorPages(ErrorPages const &rhs);
		~ErrorPages();
		void clear();
		ErrorPages &operator=(ErrorPages const &rhs);


		// 400
		std::string	error_400;
		std::string	error_403;
		std::string	error_404;
		std::string	error_405;
		std::string	error_408;
		std::string	error_413;
		// 500
		std::string	error_500;
		std::string	error_501;
		std::string	error_502;
		std::string	error_505;

	};

	struct Accept: Conf
	{
		Accept();
		Accept(Accept const &rhs);
		~Accept();
		void clear();

		std::vector<std::string> methods;
	};

	struct	Location: Conf
	{
		Location();
		Location(Data::Server const &context);
		Location(Location const &rhs);
		~Location();
		void clear();

		std::string							uri;
		std::string 						root;
		std::string							directory_file;
		std::string 						index;
		bool								autoindex;
		Data::Accept						accepted_methods;
		std::string							redirection;
        std::string                         cgi;
        std::string                         upload_path;
	};

	struct Server: Conf
	{
		Server();
		Server(const Data::Server &rhs);
		~Server();
		void clear();

		std::vector<int>					ports;
		std::vector<std::string>			names;
		std::string 						ip;
		// All this attributes have a default values.

		Data::Accept						accepted_methods;
		std::string 						root;
		std::string 						index;
		size_t 								max_body_size;
		ErrorPages							errors;
		std::vector<Data::Location>		locations;
	};

	struct Line
	{
		Line();
		Line(Line const &rhs);
        Line(std::string const &raw, std::string const &pre, size_t n);
		Line &operator=(Line const &rhs);
		~Line();

        void tokenize(void);
        void update(std::string const &new_line);

		std::string					key;
		std::string					raw;
        std::string					pre;
		std::vector<std::string>	tokens;
		size_t 						n;
	};
}
std::ostream &operator<<(std::ostream &os, const Data::Line &line);
std::ostream &operator<<(std::ostream &os, const Data::Location &location);

#endif
