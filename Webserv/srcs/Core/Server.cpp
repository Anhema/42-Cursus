#include "Server.hpp"
#include "../Logger/Logger.hpp"


Server::Server(Data::Server options, int port):
		m_ip(options.ip),
		m_port(port),
		m_socketAddress_len(sizeof(m_socketAddress)),
		m_config(options)
{
	for (int i = 0; i < Server::maxEvents; i++)
		this->message[i].setConfig(options);
	this->m_startSocketAddress();
	this->m_startSocket();
	this->m_bindSocket();
	this->m_startListen();
}

Server::~Server()
{
    cout << "Closing socket: " << m_socket_fd << "\n";
	close(m_socket_fd);
}

fd Server::getSocket() const { return m_socket_fd; }

void Server::m_startSocketAddress()
{
	this->m_socketAddress.sin_family = AF_INET;
	this->m_socketAddress.sin_port = htons(this->m_port);
	this->m_socketAddress.sin_addr.s_addr = inet_addr(m_ip.c_str());

	Logger::log("Socket address initialized succesfully", INFO);
}

void Server::m_startSocket()
{
	this->m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (this->m_socket_fd < 0)
		throw (std::runtime_error("initialing fd"));

	const char reuse = 1;

	if (setsockopt(this->m_socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0)
		throw (std::runtime_error("SO_REUSEADDR"));

	fcntl(this->m_socket_fd, F_SETFL, O_NONBLOCK);

	Logger::log("Socket created succesfully", INFO);
}

void Server::m_bindSocket()
{
	if (bind(m_socket_fd, (sockaddr *)&m_socketAddress, m_socketAddress_len) < 0)
		throw (std::runtime_error("can't bind socket"));
	Logger::log("Socket binded succesfully", INFO);
}

void Server::enableEvent(int kq, const fd event_fd, struct kevent *k_struct, short event) const
{
	EV_SET(k_struct, event_fd, event, EV_ADD | EV_ENABLE, 0, 0, 0);

	if (kevent(kq, k_struct, 1, NULL, 0, NULL) < 0)
		throw (std::runtime_error("kqueue failed to add event"));
}

void Server::disableEvent(int kq, const fd event_fd, struct kevent *k_struct, short event) const
{
	EV_SET(k_struct, event_fd, event, EV_ADD | EV_DISABLE, 0, 0, 0);

	if (kevent(kq, k_struct, 1, NULL, 0, NULL) < 0)
		throw (std::runtime_error("kqueue failed to disable event"));
}

void Server::enableWrite(int kq, const fd event_fd) const
{
	EV_SET((struct kevent *)&this->m_write_event, event_fd, EVFILT_WRITE, EV_ENABLE, 0, 0, 0);

	if (kevent(kq, &this->m_write_event, 1, NULL, 0, NULL) < 0)
		throw (std::runtime_error("kqueue failed to enable write"));
}

void Server::disableWrite(int kq, const fd event_fd) const
{
	EV_SET((struct kevent *)&this->m_write_event, event_fd, EVFILT_WRITE, EV_DISABLE, 0, 0, 0);

	if (kevent(kq, &this->m_write_event, 1, NULL, 0, NULL) < 0)
		throw (std::runtime_error("kqueue failed to disable write"));
}

void Server::disconnectClient(int kq, const fd client)
{
	EV_SET((struct kevent *)&this->m_write_event, client, EVFILT_WRITE, EV_DELETE, 0, 0, 0);
	if (kevent(kq, &this->m_write_event, 1, NULL, 0, NULL) < 0)
		throw (std::runtime_error("kqueue failed to delete write"));

	EV_SET((struct kevent *)&this->m_read_event, client, EVFILT_READ, EV_DELETE, 0, 0, 0);
	if (kevent(kq, &this->m_read_event, 1, NULL, 0, NULL) < 0)
		throw (std::runtime_error("kqueue failed to delete read"));

	stringstream ss;

	ss << "EV EOF: fd " << client;
	Logger::log(ss.str(), INFO);

	close(client);
}

void Server::m_startListen()
{
	stringstream ss;

	if (listen(m_socket_fd, Server::max_listen_queue) < 0)
		throw (std::runtime_error("listen failed to start"));

	ss << "Socked with fd: "
	   << m_socket_fd
        <<" started listening on address: "
		<< inet_ntoa(m_socketAddress.sin_addr)
		<< " port: "
		<< ntohs(m_socketAddress.sin_port);
	Logger::log(ss.str(), INFO);
}

fd Server::acceptClient(std::map<fd, Server *> &active_fd, int kq) const
{

    const fd	new_client = accept(this->m_socket_fd, (sockaddr *)&m_socketAddress, (socklen_t *)&m_socketAddress);

    if (new_client == -1)
        throw (std::runtime_error("Failed to accept incoming connection"));

	fcntl(new_client, F_SETFL, O_NONBLOCK);
	this->enableEvent(kq, new_client, (struct kevent *)&this->m_read_event, EVFILT_READ);
	this->disableEvent(kq, new_client, (struct kevent *)&this->m_write_event, EVFILT_WRITE);

    stringstream ss;

    ss << "Accepted connection: " << new_client;
    Logger::log(ss.str(), INFO);
	active_fd[new_client] = (Server *)this;
    return (new_client);
}
