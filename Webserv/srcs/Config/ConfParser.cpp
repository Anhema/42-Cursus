#include "ConfParser.hpp"

void WebServ::ConfParser::print() const
{
    for (std::vector<Data::Server >::const_iterator it = this->m_serverBrackets.begin(); it != this->m_serverBrackets.end(); it++)
    {
        cout << "=====NEW BRACKET====\n";
        cout << "Ip -> " << (it)->ip << "\n";
        cout << "Ports -> ";
        Utils::print_vector((it)->ports);

        cout << "Server Names -> ";
        Utils::print_vector((it)->names);

        cout << "Root -> " << (it)->root << "\n";
        cout << "Index -> " << (it)->index << "\n";

        cout << "Accepted methods -> ";
        Utils::print_vector(it->accepted_methods.methods);
        cout << "Max Body -> " << (it)->max_body_size << "\n";

        cout << "Error Pages\n";
		cout << "400 -> " << (it)->errors.error_400 << "\n";
		cout << "403 -> " << (it)->errors.error_403 << "\n";
        cout << "404 -> " << (it)->errors.error_404 << "\n";
		cout << "405 -> " << (it)->errors.error_405 << "\n";
		cout << "408 -> " << (it)->errors.error_408 << "\n";
		cout << "413 -> " << (it)->errors.error_413 << "\n";
		cout << "500 -> " << (it)->errors.error_500 << "\n";
		cout << "501 -> " << (it)->errors.error_501 << "\n";
        cout << "502 -> " << (it)->errors.error_502 << "\n";
		cout << "505 -> " << (it)->errors.error_505 << "\n";

        if ((it)->locations.empty())
            cout << "No locations found\n";
        else
        {
            for (std::vector<Data::Location>::const_iterator location_it = it->locations.begin(); location_it != (it)->locations.end(); location_it++)
            {
 				cout << *location_it;
            }
        }
    }
}

WebServ::ConfParser::ConfParser(const std::string &file): Parser::Reader(file), m_serverBracket_count(-1), m_locationBracket_count(-1) {

}

WebServ::ConfParser::~ConfParser() {
    this->m_serverBrackets.clear();
    cout << "Parser destructed\n";

}

void WebServ::ConfParser::init()
{
	this->m_rules.key_end = "";
	this->m_rules.useSemicolon = false;
	this->m_rules.comment = '#';
	this->m_rules.bracket_opener = '{';
	this->m_rules.bracket_closer = '}';
	this->m_rules.extension = "conf";
    this->m_rules.line_delimiter = '\n';
	this->m_checkFile();
	this->m_BlockHandlers["server"] = Parser::BlockHandler::handlerFactory<WebServ::ServerBlockParser>();
    this->m_BlockHandlers["location"] = Parser::BlockHandler::handlerFactory<WebServ::LocationBlockParser>();
	this->m_BlockHandlers["accept"] = Parser::BlockHandler::handlerFactory<WebServ::AcceptMethodBlockParser>();
	this->m_BlockHandlers["errors"] = Parser::BlockHandler::handlerFactory<WebServ::ErrorPageBlockParser>();

}

void WebServ::ConfParser::add_context(Data::Server &context, Data::Location &location)
{
    cout << "pre methods: " << " for uri: " << location.uri << "\n";
    Utils::print_vector(location.accepted_methods.methods);
    cout << "\n";
	cout << "Location path: " << location.upload_path << "\n";
	if (location.accepted_methods.methods.empty())
		location.accepted_methods.methods = context.accepted_methods.methods;
	if (location.root.empty())
		location.root = context.root;
}



void WebServ::ConfParser::save(Data::Conf *data)
{
    static int last_server_idx = -1;
    static int last_location_idx = -1;

    if (Data::Server *server = dynamic_cast<Data::Server *>(data))
    {
        this->m_serverBrackets.push_back(*server);
		cout << "resetting location index\n";
        last_server_idx++;
		last_location_idx = -1;
		cout << "Saving at server: " << last_server_idx <<endl;
        this->m_serverBracket_count++;
    }
    else if (Data::Location *location = dynamic_cast<Data::Location *>(data))
    {
        this->m_serverBrackets.at(last_server_idx).locations.push_back(*location);
		this->m_locationBracket_count++;
        last_location_idx++;
		cout << "Saving at server "  << last_server_idx << " at location: " << last_location_idx << " " << location->uri << endl;
    }
	else if (Data::Accept *accept = dynamic_cast<Data::Accept *>(data))
	{
		this->m_serverBrackets.at(last_server_idx).locations.at(last_location_idx).accepted_methods.methods = accept->methods;
        cout << "Saving at server: " << last_server_idx << " at location: " << last_location_idx << "\n";
	}
	else if (Data::ErrorPages *error_page = dynamic_cast<Data::ErrorPages *>(data))
	{
		this->m_serverBrackets.at(last_server_idx).errors = *error_page;
	}
    else
	{
		throw (std::runtime_error("casting in confParser save"));
	}
	data->clear();
}

void WebServ::ConfParser::start()
{
	this->m_find_bracket();
	if (this->total_depth != 0)
		throw (std::invalid_argument("Keys Not Closed"));

	for (std::vector<Data::Server>::iterator iterator = this->m_serverBrackets.begin(); iterator != this->m_serverBrackets.end(); iterator++)
	{
		for (std::vector<Data::Location>::iterator it = iterator->locations.begin(); it != iterator->locations.end(); it++)
			add_context(*iterator, *it);
	}
}


std::vector<Data::Server> WebServ::ConfParser::getBrackets() const
{
    return this->m_serverBrackets;
}


void WebServ::ConfParser::validate() {
	for (std::vector<Data::Server>::iterator it = this->m_serverBrackets.begin(); it != this->m_serverBrackets.end(); it++)
		validate_server(*it);
}

void WebServ::ConfParser::validate_server(Data::Server &bracket) {
	if (bracket.ip.empty())
		throw (std::invalid_argument("No ip found"));
	if (bracket.ports.empty())
		throw (std::invalid_argument("No port found"));

	for (std::vector<Data::Location>::iterator it = bracket.locations.begin(); it != bracket.locations.end(); it++)
		validate_location(*it);
}

void WebServ::ConfParser::validate_location(Data::Location &bracket) {
	if (bracket.uri.empty())
		throw (std::invalid_argument("No uri found"));
}
