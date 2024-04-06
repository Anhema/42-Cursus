#include "Message.hpp"
#include "Logger.hpp"
#include <sys/socket.h>
#include "Utilities.hpp"
#include <fcntl.h>

Message::Message(): m_responseCode(HttpStatus::OK), finishedReading(false)
{
	this->m_readStatus = Request::HEADER;
	this->m_body.body_has_headers = false;
}

Message::~Message() {}

string &Message::getConnectionType() { return this->m_request.connection; }

void Message::setConfig(Data::Server &config)
{
	this->m_configuration = config;
}

std::string Message::m_createFile(const std::string &filename, const std::string &extension)
{
	char			time_str[100];
	time_t 			t;
	struct tm		*time_ptr;

	t = time(NULL);
	time_ptr = localtime(&t);
	strftime(time_str, sizeof(time_str), "%d-%m-%y_%H-%M", time_ptr);

	string composition_name;
	if (this->m_body.data.empty() || this->m_body.file_name.empty() || this->m_current_location->upload_path.empty())
	{
		std::string content_disposition = this->m_request.headers.find("Content-Disposition")->second;

		if (content_disposition.empty())
			return ("400");

		this->m_body.file_name = content_disposition.substr(content_disposition.find("filename=") + 9, std::string::npos);
		this->m_body.file_name = this->m_body.file_name.substr(1, this->m_body.file_name.size() - 2);
		this->m_body.file_extension = Utils::get_extension(this->m_body.file_name);
		if (this->m_body.data.empty() || this->m_body.file_name.empty() || this->m_current_location->upload_path.empty())
			return ("400");
	}

	composition_name.append(this->m_current_location->upload_path + "/");
	composition_name.append(filename);
	composition_name.append(time_str);
	composition_name.append(".");
	composition_name.append(extension);

	std::ofstream outfile(composition_name, std::ios::out | std::ios::binary);

	string			needle;

	needle.append("\r\n");
	needle.append(this->m_body.boundary);

	std::vector<char>::iterator data_end = this->m_body.data.end() - 1;
	size_t i = 0;

	while (data_end != this->m_body.data.begin())
	{
		if (i == needle.size())
			break;
		if (*data_end == needle.at(needle.size() - 1 - i))
			i++;
		data_end--;
	}

	for (std::vector<char>::iterator it = this->m_body.data.begin(); it != data_end; it++)
		outfile.write(&*it, 1);
	return ("");
}

std::string Message::error_page(std::string error)
{
	std::ostringstream	message;
	std::string			error_name;
	std::string 		path;

	if (error == "400")
	{
		path = this->m_configuration.errors.error_400;
		error_name = "Bad Request";
	}
	else if (error == "403")
	{
		path = this->m_configuration.errors.error_403;
		error_name = "Forbidden";
	}
	else if (error == "404")
	{
		error_name = "Not Found";
		path = this->m_configuration.errors.error_404;

	}
	else if (error == "405")
	{
		path = this->m_configuration.errors.error_405;
		error_name = "Method Not Allowed";
	}
	else if (error == "408")
	{
		path = this->m_configuration.errors.error_408;
		error_name = "Request Timeout";
	}
	else if (error == "413")
	{
		path = this->m_configuration.errors.error_413;
		error_name = "Payload Too Large";
	}
	else if (error == "500")
	{
		path = this->m_configuration.errors.error_500;
		error_name = "Internal Server Error";
	}
	else if (error == "501")
	{
		path = this->m_configuration.errors.error_501;
		error_name = "Not Implemened";
	}
	else if (error == "502")
	{
		path = this->m_configuration.errors.error_502;
		error_name = "Bad Gateway";
	}
	else if (error == "505")
	{
		path = this->m_configuration.errors.error_505;
		error_name = "Not Implemented";
	}

	this->m_response.htmlFile = Utils::read_file(this->m_configuration.root + path);

	if (this->m_response.htmlFile.empty())
	{
		message << "HTTP/1.1 200 OK\r\n Content-Type: text/plain\r\nContent-Length: 3\r\n\r\n" << "404";
	}
	else
	{
		this->m_response.extension = "html";
		message << "HTTP/1.1 "<< error << " " << error_name << "\r\nContent-Status: text/" << this->m_response.extension
				<< "\r\nContent-Length: " << this->m_response.htmlFile.size() << "\r\n\r\n" << this->m_response.htmlFile;
	}

	this->m_server_message = message.str();
	return (message.str());
}

std::string Message::m_get_expanded_uri(const string &path)
{
	std::vector<std::string> split_path = Utils::split(path, '/');

	std::string expanded_uri;

	for (std::vector<std::string>::iterator split = split_path.begin(); split != split_path.end(); split++)
	{
		for (std::vector<Data::Location>::iterator it = this->m_configuration.locations.begin(); it != this->m_configuration.locations.end(); it++)
		{
			if ((it->uri == "/" || *split == "/") && it->uri == "/")
				expanded_uri.append(it->root);
			else if (Utils::eraseAll(it->uri, '/') == *split)
				expanded_uri.append(it->root);
		}
	}
	return expanded_uri;
}

std::string Message::m_get_uri_segment_root(string &filter) {

	for (std::vector<Data::Location>::iterator it = this->m_configuration.locations.begin(); it != this->m_configuration.locations.end(); it++)
		if (it->uri == filter)
			return it->root;

	return std::string(filter);
}

std::string Message::m_parse_uri(const string uri)
{
	this->m_uri.location_filter.push_back("/");
	if (uri == "/")
		this->m_uri.segments.push_back("/");
	else
	{
		this->m_uri.segments = Utils::split(uri, '/');

		for (std::vector<std::string>::iterator it = this->m_uri.segments.begin(); it != this->m_uri.segments.end(); it++)
			*it = '/' + *it;
		this->m_uri.file = *(this->m_uri.segments.end() - 1);
		this->m_uri.file.erase(this->m_uri.file.begin(), this->m_uri.file.begin() + 1);
		if (this->m_uri.segments.size() == 1)
			this->m_uri.location_filter.push_back("/");
	}

	if (this->m_uri.segments.size() == 1)
	{
		std::string filter("/");
		std::string expanded_root = this->m_get_uri_segment_root(filter);
		this->m_uri.expanded.append(expanded_root);
	}
	else
	{
		for (std::vector<std::string>::iterator it = this->m_uri.segments.begin(); it != this->m_uri.segments.end(); it++)
		{
			std::string expanded_root = this->m_get_uri_segment_root(*it);
			if (*it == expanded_root)
				this->m_uri.expanded.append(expanded_root);
		}
	}

	for (std::vector<std::string>::iterator it = this->m_uri.segments.begin(); it != this->m_uri.segments.end(); it++)
		this->m_uri.location_filter.push_back(*it);

	this->m_uri.is_dir = Utils::is_directory(this->m_uri.expanded);
	if (this->m_uri.is_dir)
	{
		if (*(this->m_uri.expanded.end() - 1) != '/')
			this->m_uri.expanded.push_back('/');
		this->m_uri.expanded.append(this->m_uri.file);
	}
	this->m_uri.is_dir = Utils::is_directory(this->m_uri.expanded);

	return std::string("");
}

string Message::m_update_location(const string &path)
{
	static Data::Location default_location;
	std::vector<std::string> location_segments(Utils::split(path, '/'));

	std::string expanded_uri = this->m_get_expanded_uri(path);

	this->m_request.plain_uri.substr(0, this->m_request.plain_uri.find_last_of('/', 1));
	for (std::vector<std::string>::reverse_iterator filter = this->m_uri.location_filter.rbegin(); filter != this->m_uri.location_filter.rend(); filter++)
	{
		for (std::vector<Data::Location>::iterator it = this->m_configuration.locations.begin(); it != this->m_configuration.locations.end(); it++)
		{
			if (*filter == it->uri)
			{
				this->m_current_location = &(*it);
				this->m_expanded_root.clear();
				return ("");
			}

		}

	}
	default_location.uri = path;
	this->m_current_location = &default_location;
	return (this->m_current_location->root);
}

bool Message::m_is_autoindex()
{
	bool enable_and_no_index = this->m_current_location->autoindex && this->m_current_location->index.empty();

	std::string tryfile = this->m_current_location->root + this->m_uri.expanded;

	return ((enable_and_no_index && ((this->m_request.plain_uri == this->m_current_location->uri) || (this->m_request.plain_uri == this->m_current_location->uri  + '/'))));
}

std::string Message::m_get_path()
{

	std::string path(this->m_uri.expanded);

	if (path.find(this->m_current_location->root) != 0 && this->m_current_location->index.empty())
		path = this->m_current_location->root + path;
	else if (path.find(this->m_current_location->index) == std::string::npos
			&& ("/" + this->m_uri.file == this->m_current_location->uri))
		path = this->m_current_location->root + "/" + this->m_current_location->index;

	if (!this->m_current_location->index.empty()
		&& this->m_uri.is_dir && this->m_uri.file.empty()
		&& (path.find(this->m_current_location->index) == std::string::npos))
		path.append(this->m_current_location->index);
	else if (!this->m_uri.is_dir)
	{
		Utils::deleteConsecutives(path, '/');
		if (path.find(this->m_current_location->root) != 0)
			path = this->m_current_location->root + path;
		return path;

	}
	else if (this->m_uri.is_dir && this->m_current_location->index.empty())
		path.append(this->m_uri.file);
	else if (!this->m_current_location->index.empty() && (path.find(this->m_current_location->index) == std::string::npos))
		path.append(this->m_current_location->index);

	Utils::deleteConsecutives(path, '/');
	return path;
}

std::string Message::m_get()
{
	std::ostringstream	message;
	std::string 		args = "";
	std::string 		type = "";
	std::string 		x_type = "";

	std::string 		path(this->m_get_path());

	if (path.find_first_of("?"))
	{
		std::vector<string> vec = Utils::split(path, '?');
		if (vec.size() > 1)
		{
			args = vec[1];
			path = vec[0];
			vec.clear();
		}
	}

	std::ifstream ifs(path);

	if (access(path.c_str(), F_OK) != 0)
		message << this->error_page("404");
	else if (access(path.c_str(), R_OK) != 0)
		message << this->error_page("403");
	else if (!ifs.is_open())
		message << this->error_page("400");
	
	CGI cgi;
	
	if (Utils::get_extension(path) == "php" || Utils::get_extension(path) == "py" || Utils::get_extension(path) == "sh")
	{
		this->m_response.body = cgi.exec_cgi(path, args, this->m_request.method);
		if (this->m_response.body == "timeout")
			return (this->error_page("408"));
		if (this->m_response.body == "403")
			return (this->error_page("403"));
		if (this->m_response.body == "Error")
			return (this->error_page("502"));

		message << "HTTP/1.1 200 OK\nContent-Type: text/html\r\n"
			<< "Content-Length: " << this->m_response.body.size() << "\r\n\r\n" << this->m_response.body;
		return (message.str());
	}

	this->m_response.htmlFile = Utils::read_file(path);
	this->m_response.extension = Utils::get_extension(path);
	message << "HTTP/1.1 "<< this->m_responseCode << " OK\nContent-Type:";
	if (this->m_response.extension == "png" || this->m_response.extension == "jpg")
		message << "image/" + this->m_response.extension;
	else if (this->m_response.extension == "js")
	{
		message << "text/javascript";
		x_type = "\r\nx-content-type-options: script";
	}
	else
		message << "text/" + this->m_response.extension;
	message << x_type << "\r\ncontent-length: " << this->m_response.htmlFile.size() << "\r\n\r\n" << this->m_response.htmlFile;
	return (message.str());
}

std::string Message::m_post()
{
	std::ostringstream message;
	std::string path(this->m_get_path());

	std::ifstream ifs(path, std::ios::binary);

	CGI cgi;
	if (this->m_request.content_length > 0)
	{
		if (access(path.c_str(), F_OK) != 0)
			return (this->error_page("404"));
		
		string content;
		for (std::vector<char>::iterator it = this->m_body.data.begin(); it != this->m_body.data.end(); it++)
			content += (*it);
		this->m_response.body = cgi.exec_cgi(path, content, this->m_request.method);
	}
	else
	{
		if (access(path.c_str(), F_OK) != 0)
			return (this->error_page("404"));
		
		this->m_response.body = cgi.exec_cgi(path, "", this->m_request.method);
	}
	if (this->m_response.body == "timeout")
		return (this->error_page("408"));
	if (this->m_response.body == "403")
		return (this->error_page("403"));
	if (this->m_response.body == "Error")
		return (this->error_page("502"));
	if (this->m_response.body == "")
	{
		if (this->m_createFile(this->m_body.file_name, this->m_body.file_extension).empty())
		{
			this->m_response.body = "File Uploaded";
			this->m_response.extension = "text/html";
			message << "HTTP/1.1 200 OK\nContent-Type: text/html\n"
					<< "Content-Length: " << this->m_response.body.size() << "\r\n\r\n" << this->m_response.body;
			return (message.str());
		}
		else
			return (this->error_page("400"));
	}
	this->m_response.extension = "text/html";
	message << "HTTP/1.1 200 OK\nContent-Type: text/html\n"
			<< "Content-Length: " << this->m_response.body.size() << "\r\n\r\n" << this->m_response.body;
	return (message.str());
}

std::string Message::m_delete()
{
	std::ostringstream message;
	std::string path(this->m_get_path());

	std::ifstream ifs(path);

	int file_status = Utils::file_exists(path);

	if (file_status == ENOENT)
		message << this->error_page("404");
	else if (access(path.c_str(), R_OK) != 0)
		message << this->error_page("403");
	else if (!ifs.is_open())
		message << this->error_page("400");
	else
	{
		this->m_response.htmlFile = Utils::read_file(path);
		unlink(path.c_str());
		this->m_response.extension = Utils::get_extension(path);
		message << "HTTP/1.1 200 OK\nContent-Status: text/" << this->m_response.extension
				<< "\nContent-Length: " << this->m_response.htmlFile.size() << "\r\n\r\n" << this->m_response.htmlFile;
	}
	return (message.str());
}

void print_headers(std::map<string, string> headers, t_request &request)
{
	cout << "URI -> " << request.plain_uri << "\n";
	cout << "Target -> " << request.target << "\n";
	cout << "Method -> " << request.method << "\n";
	for (std::map<string, string>::iterator it = headers.begin(); it != headers.end(); it++)
	{
		cout << "(" << it->first << ") -> (" << it->second << ")\n";
	}

}

string Message::m_readHeader(const fd client)
{
	string 			header = "";
	ssize_t			read_bytes = 0;
	size_t			err_count = 0;
	char			buffer;

	while (header.find(HEADER_END) == string::npos)
	{
		read_bytes = recv(client, &buffer, 1, 0);
		if (read_bytes == -1)
		{
			err_count++;
		}
		else
		{
			err_count = 0;
			header.push_back(buffer);
		}
		if (err_count >= Message::s_maxRecvErrors)
		{
			Logger::log("Bad Header", WARNING);
			for (size_t i = 0; i < header.size(); i++)
				this->m_body.data.push_back(header[i]);
			if (!header.empty())
			{
				Logger::log("READ STATUS -> FINISHED BODY", INFO);
				this->m_readStatus = Request::FINISHED_BODY;
			}
			break;
		}
		if (this->m_readStatus == Request::BODY_HEADER)
			this->m_body.current_read += read_bytes;
	}
	return header;
}

void Message::m_parseHeader(std::string &header)
{
	if (header == "")
	{
		this->m_request.method = "";
		this->m_request.plain_uri = "";
		this->m_request.version = "";
		this->m_parseBody(header);
		this->m_readStatus = Request::BODY;
		this->finishedReading = true;
		return;
	}
	
	std::vector<std::string> request = Utils::split(header, '\n');
	std::vector<std::string>::iterator line = request.begin();
	std::vector<std::string> r_line = Utils::split((*line), ' ');

	this->m_request.method = r_line[0];
	this->m_request.plain_uri = r_line[1];
	this->m_request.version = r_line[2];


	while (++line != request.end())
	{
		char *tmp_key = std::strtok((char *)line->c_str(), ": ");
		if (!tmp_key)
			break;

		Utils::capitalize(tmp_key, " -");

		const string key(tmp_key);

		char *tmp_value = std::strtok(NULL, "\n\r");
		if (!tmp_value)
			break;
		const string value(&tmp_value[1]);

		this->m_request.headers.insert(std::make_pair(key, value));
	}

	this->m_request.connection = this->m_request.headers["Connection"];
	this->m_request.content_length = (size_t)std::atoi(this->m_request.headers["Content-Length"].c_str());
	this->m_request.transfer_encoding = this->m_request.headers["Transfer-Encoding"];

	if (this->m_request.headers["Host"].find(":"))
		this->m_request.headers["Host"] = this->m_request.headers["Host"].substr(0, this->m_request.headers["Host"].find(":"));
	if (this->m_request.transfer_encoding == "chunked")
	{
		Logger::log("Chunked request incoming", INFO);
		this->m_readStatus = Request::CHUNKED_TRANSFER;
	}
	if (this->m_request.content_length)
	{
		Logger::log("READ STATUS -> BODY HEADER", INFO);
		this->m_parseBody(header);
		this->m_readStatus = Request::BODY_HEADER;
	}
	else
	{
		Logger::log("Finished read -> true", INFO);
		this->finishedReading = true;
	}
}

void Message::m_parseBody(const std::string &header)
{
	string  filename;

	if (this->m_readStatus == Request::FINISHED_BODY)
		return;

	string boundary = "";
	std::vector<std::string> headers = Utils::split(header.substr(header.find("\r\n"), header.size() - 1), ';');

	this->m_body.boundary = header.substr(0, header.find("\r\n"));
	
	for (size_t i = 0; i < headers.size(); i++)
	{
		if (Utils::split(headers[i], '=')[0] == " filename")
		{
			string name = Utils::split(Utils::split(headers[i], '=')[1], "\r\n")[0];
			name.replace(0, 1, "");
			name.replace(name.size() - 1, 1, "");
			this->m_body.file_name = name.substr(name.find_first_of("\"") + 1, name.find_last_of("."));
			this->m_body.file_extension = Utils::get_extension(name);
		}
	}
}

void Message::m_readBody(const fd client, const size_t fd_size)
{
	static size_t	totalRead;
	size_t 			read_errors = 0;
	size_t 			loopRead = 0;
	ssize_t 		read_bytes;
	const size_t 	buffer_size = 30720;
	char		    buffer[buffer_size];

	while (loopRead < fd_size && this->m_body.current_read < this->m_request.content_length)
	{
		read_bytes = recv(client, buffer, buffer_size, 0);

		if (read_errors >= Message::s_maxRecvErrors)
		{
			Logger::log("timeout reading handle_request", WARNING);
			break;
		}
		if (read_bytes == -1)
		{
			read_errors++;
		}
		else
			read_errors = 0;

		for (ssize_t i = 0; i < read_bytes; i++)
			this->m_body.data.push_back(buffer[i]);

		this->m_body.current_read += read_bytes;
		loopRead += read_bytes;
	}
	if (this->m_body.current_read >= this->m_request.content_length || this->m_request.content_length == 0)
	{
		Logger::log("READ STATUS -> FINISHED BODY", INFO);
		this->m_readStatus = Request::FINISHED_BODY;
		this->finishedReading = true;
		totalRead = 0;
	}
}



void Message::m_read_chunk(const fd client, __unused size_t fd_size)
{
	ssize_t 		read_bytes = 0;
	std::string 	header;
	std::string 	chunk;
	char 			header_buff;
	char 			chunk_buff;

	while (header.find("\r\n") == string::npos)
	{
		read_bytes = recv(client, &header_buff, 1, 0);
		header.push_back(header_buff);
		if (this->m_readStatus == Request::BODY_HEADER)
			this->m_body.current_read += read_bytes;
	}

	int chunk_size = std::atoi(header.c_str());

	if (chunk_size == 0)
	{
		Logger::log("Last Chunk detected status -> Finished read", INFO);
		this->m_readStatus = Request::FINISHED_BODY;
	}

	read_bytes = 0;

	while (chunk.find("\r\n") == string::npos)
	{
		read_bytes = recv(client, &chunk_buff, 1, 0);
		chunk.push_back(chunk_buff);
		this->m_body.data.push_back(chunk_buff);
	}
}

void Message::handle_request(const fd client, size_t buffer_size)
{

	stringstream  	ss;
	stringstream  	ss_buffer;

	ss << "READ STATUS: " << this->m_readStatus;

	Logger::log(ss.str(), INFO);
	std::string header;
	switch (this->m_readStatus)
	{
		case Request::HEADER:
			header = this->m_readHeader(client);
			this->m_parseHeader(header);
			break;
		case Request::CHUNKED_TRANSFER:
			Logger::log("Handling a chunk", INFO);
			this->m_read_chunk(client, buffer_size);
			break;
		case Request::BODY_HEADER:
			Logger::log("BODY HEADER HANDLE", INFO);
			header = this->m_readHeader(client);
			if (this->m_readStatus == Request::FINISHED_BODY)
			{
				this->finishedReading = true;
				break;
			}
			this->m_parseBody(header);
			this->m_readStatus = Request::BODY;
			break;
		case Request::BODY:
			this->m_readBody(client, buffer_size);
			Logger::log("Body Read finished", INFO);
			break;
		case Request::FINISHED_BODY:
			break;
	}
}

bool Message::m_valid_method()
{
	for (std::vector<std::string>::iterator it = this->m_current_location->accepted_methods.methods.begin(); it != this->m_current_location->accepted_methods.methods.end(); it++)
		if (*it == this->m_request.method)
			return true;
	return false;
}

void Message::m_send_message(const fd client)
{
	ssize_t totalSent = 0;
	ssize_t send_bytes = 0;
	size_t err_count = 0;
	
	while (totalSent < (ssize_t)this->m_server_message.size())
	{
		send_bytes = send(client, this->m_server_message.c_str() + totalSent, this->m_server_message.size() - totalSent, 0);
		if (err_count >= Message::s_maxSendErrors)
		{
			Logger::log("timeout sending handle_request", WARNING);
			break;
		}
		if (send_bytes == -1)
		{
			err_count++;
		}
		else
			err_count = 0;
		totalSent += send_bytes;
	}
}

void Message::m_make_redir(void)
{
	std::stringstream message;
	const std::string EOL("\r\n");

	message << "HTTP/1.1" << " " << "301" << " " << "Moved Permanently" << EOL
	<< "Location: " << this->m_current_location->redirection << EOL
	<< "Connection: close" << EOL
	<< "Content-Length: 0" << EOL
	<< EOL;
	this->m_server_message = message.str();
}

std::string Message::m_make_html_link(const string &link)
{
	std::string result;

	result.append("<li>");
	result.append("<a href=\"");
	result.append(link);
	result.append("\">");
	result.append(link);
	result.append("</a>");
	result.append("</li>");
	return result;
}

void Message::m_make_autoindex(void)
{
	const std::string path(this->m_current_location->root);
	const std::string EOL("\r\n");
	std::stringstream message;
	std::stringstream html;

	html	<< "<html>\n<head>\n\t<title>Directory Links</title>\n</head>\n<body>\n\t"
			<< "<h1>Directory Links</h1>\n\t<ul>\n";

	std::vector<std::string> dir_entries = Utils::read_dir(path);

	for (std::vector<std::string>::iterator it = dir_entries.begin(); it != dir_entries.end(); it++)
		html << "\t\t" << this->m_make_html_link(*it) << "\n";

	html << "\t</ul>\n"
			<< "</body>\n</html>"
			<< "\n";

	message << "HTTP/1.1 200 OK" << EOL
			<< "Content-Type: text/html" << EOL
			<< "Content-Length: " << html.str().size() << EOL
			<< "Connection: close" << EOL
			<< EOL
			<< html.str();
	this->m_server_message = message.str();
}

void Message::make_response(const fd client, size_t __unused buffer_size)
{
	stringstream  ss;

	Logger::log(ss.str(), INFO);
	Logger::log("New Response", WARNING);
	if (this->m_readStatus == Request::CHUNKED_TRANSFER)
	{
		Logger::log("Continue Header Sent", INFO);
		this->m_server_message = "HTTP/1.1 100 Continue\r\n\r\n";
		this->m_send_message(client);
		return;
	}

	if (this->m_request.plain_uri.empty())
	{
		this->error_page("400");
		return;
	}

	if (this->m_request.method == "")
		return;

	this->m_parse_uri(this->m_request.plain_uri);
	this->m_update_location(this->m_request.plain_uri);

	if (!this->m_valid_method())
	{
		this->error_page("405");
		this->m_send_message(client);
		return;
	}
	if (!this->m_valid_server_name())
	{
		this->error_page("403");
		this->m_send_message(client);
		return;
	}
	if (!this->m_current_location->redirection.empty())
	{
		this->m_make_redir();
		this->m_send_message(client);
		return;
	}
	if (this->m_is_autoindex())
	{
		std::vector<std::string> uri_segments(Utils::split(this->m_request.plain_uri, '/'));

		if ('/' + *(uri_segments.end() -1) != this->m_current_location->uri)
		{
			this->error_page("404");
			this->m_send_message(client);
			return;

		}
		this->m_make_autoindex();
		this->m_send_message(client);
		return;
	}
	else if (*(this->m_request.plain_uri.end() - 1) == '/' && !this->m_current_location->autoindex && this->m_current_location->index.empty())
	{
		this->error_page("404");
		this->m_send_message(client);
	}

	if (this->m_body.data.size() > this->m_configuration.max_body_size)
	{
		this->error_page("413");
		this->m_send_message(client);
	}

	std::ostringstream message;
	if (this->m_request.method == GET_METHOD)
		this->m_server_message = m_get();
	else if (this->m_request.method == DELETE_METHOD)
		this->m_server_message = this->m_delete();
	else if (this->m_request.method == POST_METHOD)
		this->m_server_message = this->m_post();
	else
		this->error_page("400");

	this->m_send_message(client);
}

bool Message::m_valid_server_name(void)
{
	std::string host = this->m_request.headers.find("Host")->second;
	 if (host.empty())
		 return false;

	for (std::vector<std::string>::iterator it = this->m_configuration.names.begin(); it != this->m_configuration.names.end(); it++)
	{
		if (*it == host)
			return true;
	}
	return true;
}

void Message::reset()
{
	Logger::log("Resetting message class", INFO);
	this->m_body.data.clear();
	this->m_request.method.clear();
	this->m_request.target.clear();
	this->m_request.connection.clear();
	this->m_request.plain_uri.clear();
	this->m_request.version.clear();
	this->m_request.content_length = 0;
	this->m_request.headers.clear();

	this->m_response.htmlFile.clear();
	this->m_response.body.clear();
	this->m_response.extension.clear();

	this->m_responseCode = HttpStatus::OK;
	this->m_readStatus = Request::HEADER;
	this->m_server_message.clear();
	this->finishedReading = false;

	// Uri struct
	this->m_uri.segments.clear();
	this->m_uri.expanded.clear();
	this->m_uri.file.clear();
	this->m_uri.location_filter.clear();
	this->m_body.current_read = 0;
	this->m_body.body_has_headers = false;
}
