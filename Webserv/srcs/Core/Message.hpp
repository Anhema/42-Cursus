#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include "../Utilities/Utilities.hpp"
# include <unistd.h>
# include "DataContainers.hpp"
# include "CGI.hpp"

# define HEADER_END "\r\n\r\n"


namespace Request
{
	enum Status
	{
		HEADER,
		BODY,
		BODY_HEADER,
		FINISHED_BODY,
		CHUNKED_TRANSFER
	};
}

#define HTTP_1_1 "HTTP/1.1";

typedef struct s_uri
{
	std::vector<std::string>			segments;
	std::string 						file;
	std::string							expanded;
	std::vector<std::string>			location_filter;
	bool								is_dir;
}	t_uri;

typedef struct s_body
{
	std::vector<char>					data;
	string 								file_name;
	string 								file_extension;
	string 								boundary;
	std::map<std::string, std::string>	headers;
	size_t 								current_read;
	bool								body_has_headers;
}	t_body;

typedef struct s_request
{
	std::string							method;
	std::string							target;
	std::string							connection;
	std::string							plain_uri;
	std::string							version;
	std::string 						transfer_encoding;
	size_t 								content_length;
	std::map<std::string, std::string>	headers;
}	t_request;

typedef struct s_response
{
	std::string							htmlFile;
	std::string							extension;
	std::string							body;
}	t_response;

class Message
{

public:
	Message();
	~Message();

private:
	Data::Server			m_configuration;
	t_request				m_request;
	t_response				m_response;
	t_body 					m_body;
	HttpStatus::Code		m_responseCode;
	std::string 			m_server_message;
	Data::Location			*m_current_location;
	std::string 			m_expanded_root;
	t_uri 					m_uri;
	std::map<std::string, std::string>	chunked_headers;

private:
	// Takes the request uri and fills t_uri structures
	std::string 			m_parse_uri(const string uri);

	// Returns a location object corresponding a uri
	std::string				m_get_uri_segment_root(std::string &filter);

	// Takes the body and fills t_body structures

	bool 					m_is_autoindex();
	void					m_read_chunk(const fd client, size_t fd_size);
	std::string 			m_get_expanded_uri(const string &path);
	std::string 			m_get_path();
	std::string				m_get();
	std::string				m_post();
	std::string				m_delete();
	string					m_readHeader(const fd client);
	void					m_parseHeader(string &header);
	void 					m_parseBody(const string &header);
	void 					m_readBody(const fd client, const size_t fd_size);
	std::string				m_createFile(const string &filename, const string &extension);
	string					m_update_location(const std::string &path);
	bool					m_valid_method(void);
	void					m_send_message(const fd client);
	void					m_make_redir(void);
	void					m_make_autoindex(void);
	bool					m_valid_server_name(void);
	std::string				m_make_html_link(std::string const &link);

public:
	void 					reset(void);
	void					setConfig(Data::Server &config);
	void					make_response(const fd client, size_t buffer_size);
	void					handle_request(const fd client, size_t buffer_size);
	string					&getConnectionType(void);

	std::string				error_page(std::string error);

	bool					finishedReading;
	Request::Status			m_readStatus;

	static const int		s_maxSendErrors	= 10000;
	static const int		s_maxRecvErrors	= 10000;
};

#endif

