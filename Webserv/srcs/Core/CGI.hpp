#ifndef CGI_HPP
# define CGI_HPP

# include "Message.hpp"

typedef struct s_request t_request;
typedef struct s_body t_body;

class CGI
{
	public:
		CGI();
		~CGI();

		string exec_cgi(string file_path, string body, string method);
		char** crete_env(string file_path, t_request request, size_t contentLength, string content_type);

	private:
};

#endif
