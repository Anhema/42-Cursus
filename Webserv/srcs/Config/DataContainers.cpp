#include "DataContainers.hpp"
#include <stdexcept>
#include "sstream"
#include "Utilities.hpp"
#include <iostream>
// USE THIs AS REFERENCE FOR DEFAULTS

Data::ErrorPages::ErrorPages():
error_400("400.html"), error_403("403.html"),
error_404("404.html"), error_405("405.html"),
error_408("408.html"), error_413("413.html"),
error_500("500.html"), error_501("501.html"),
error_502("502.html"), error_505("505.html") {}

Data::ErrorPages::ErrorPages(const Data::ErrorPages &rhs):
		error_400(rhs.error_400), error_403(rhs.error_403),
		error_404(rhs.error_404), error_405(rhs.error_405),
		error_408(rhs.error_408), error_413(rhs.error_413),
		error_500(rhs.error_500), error_501(rhs.error_501),
		error_502(rhs.error_502), error_505(rhs.error_505) {}

Data::ErrorPages::~ErrorPages() {}

Data::Server::Server(): ports(), names(), ip(), accepted_methods(), root("www/"), index("index.html"), max_body_size(1000), errors(), locations()
{
	this->accepted_methods.methods.push_back(GET_METHOD);
}

Data::Server::Server(const Data::Server &rhs): ports(rhs.ports),
names(rhs.names),
ip(rhs.ip),
accepted_methods(rhs.accepted_methods),
root(rhs.root),
index(rhs.index),
max_body_size(rhs.max_body_size),
errors(rhs.errors),
locations(rhs.locations)
{
}

void Data::Server::clear()
{
	Data::Server def;

	this->accepted_methods = def.accepted_methods;
	this->index = def.index;
	this->root = def.root;
	this->ports = def.ports;
	this->ip = def.ip;
	this->locations = def.locations;
	this->errors = def.errors;
	this->max_body_size = def.max_body_size;
	this->names = def.names;
}

Data::Conf::~Conf() {
//    std::cout << "Parent Data destructed\n";
}

Data::Server::~Server() {
    //std::cout << "Destroying server data\n";
}

Data::Location::Location():
		uri(), root("www/"), directory_file(), index(),
		autoindex(false), accepted_methods(), redirection()
{
	this->accepted_methods.methods.push_back(GET_METHOD);
	this->accepted_methods.methods.push_back(POST_METHOD);
	this->upload_path = "www/uploads";
}

Data::Location::Location(Data::Server const &context):
		uri(), root(context.root), directory_file(), index(context.index),
		autoindex(false), accepted_methods(context.accepted_methods), redirection()
{}

Data::Location::Location(Location const &rhs):
		uri(rhs.uri), root(rhs.root), directory_file(rhs.directory_file), index(rhs.index),
		autoindex(rhs.autoindex), accepted_methods(rhs.accepted_methods), redirection(rhs.redirection)
{
	this->upload_path = rhs.upload_path;
}

Data::Location::~Location() { //std::cout << "Destroying Location\n";
}

Data::Line::Line(Line const &rhs): key(rhs.key), raw(rhs.raw), pre(rhs.pre), tokens(rhs.tokens), n(rhs.n) {}

Data::Line::Line() {

}

void Data::Location::clear()
{
	Data::Location def;

	this->uri = def.uri;
	this->root = def.root;
	this->index = def.index;
	this->accepted_methods = def.accepted_methods;
	this->directory_file = def.directory_file;
	this->autoindex = def.autoindex;
	this->redirection = def.redirection;
	this->cgi = def.cgi;
	this->upload_path = def.upload_path;

}

Data::Line::Line(const std::string &raw, const std::string &pre, size_t n): raw(raw), pre(pre), n(n) {}

Data::Line::~Line() {

}

void Data::Line::update(const std::string &new_line)
{
   std::swap(this->pre, this->raw);
   this->raw = new_line;
   this->n++;
}

Data::Line &Data::Line::operator=(const Data::Line &rhs) {
	this->n = rhs.n;
	this->tokens = rhs.tokens;
	this->raw = rhs.raw;
    this->pre = rhs.pre;
	this->key = rhs.key;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Data::Location &location)
{
	os << "====Location====\n";
	os << "\turi-> " << (location).uri << "\n";
	os << "\tRoot-> " << (location).root << "\n";
	os << "\tIndex-> " << (location).index << "\n";
	os << "\tUpload path -> " << location.upload_path << "\n";
	os << "\tAccept -> ";
	Utils::print_vector(location.accepted_methods.methods);
	os << "\tRedirection -> ";
	if (location.redirection.empty())
		os << "empty\n";
	else
		os << location.redirection << "\n";
	os << "\tAutoindex -> ";
	if (location.autoindex)
		os << "true\n";
	else
		os << "false\n";


	os << "\n";
	return os;
}

void Data::Line::tokenize()
{
    std::stringstream	line(raw);
    std::string 	    tmp;

    this->tokens.clear();
    this->key.clear();

    while (line >> tmp)
    {
        if (this->tokens.empty() && this->key.empty())
            this->key = tmp;
        else
            this->tokens.push_back(tmp);
    }
}

std::ostream &operator<<(std::ostream &os, const Data::Line &line)
{
    std::stringstream ss;

    ss << "current -> " << line.raw << " " << "pre -> " << line.pre << " n: " << line.n;
    os << ss.str();
    return os;
}

Data::Accept::Accept() {

}

Data::Accept::~Accept() {
	this->methods.clear();
}

Data::Accept::Accept(const Data::Accept &rhs): methods(rhs.methods) {
}

void Data::Accept::clear() {
	this->methods.clear();
}

void Data::ErrorPages::clear() {
	this->error_400 = "400.html";
	this->error_502 = "502.html";
	this->error_404 = "404.html";
}

Data::ErrorPages &Data::ErrorPages::operator=(const Data::ErrorPages &rhs) {
	this->error_400 = rhs.error_400;
	this->error_403 = rhs.error_403;
	this->error_404 = rhs.error_404;
	this->error_405 = rhs.error_405;
	this->error_408 = rhs.error_408;
	this->error_413 = rhs.error_413;
	this->error_500 = rhs.error_500;
	this->error_501 = rhs.error_501;
	this->error_502 =rhs.error_502;
	this->error_505 = rhs.error_505;
	return *this;
}
