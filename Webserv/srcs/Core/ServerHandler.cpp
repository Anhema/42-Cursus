#include "ServerHandler.hpp"

ServerHandler::ServerHandler(std::vector<Data::Server> configurations)
{
	for (std::vector<Data::Server>::iterator conf_it = configurations.begin(); conf_it != configurations.end(); conf_it++)
	{
		for (std::vector<int>::iterator port_it = conf_it->ports.begin(); port_it != conf_it->ports.end(); port_it++)
		{
			this->m_server_list.push_back(new Server(*conf_it, *port_it));
		}
	}
	this->m_startKqueue();
	this->m_monitorSockets();
}

ServerHandler::ServerHandler(int server_count): _server_count(server_count)
{
	this->m_monitorSockets();
}

ServerHandler::~ServerHandler()
{
	delete [] this->m_socketEvents;
	this->m_server_list.clear();
}


void ServerHandler::m_startKqueue()
{
	this->m_kq = kqueue();

	if (m_kq == -1)
		throw (std::runtime_error("couldn't start kqueue"));
}

void ServerHandler::m_monitorSockets()
{
	this->m_socketEvents = new struct kevent[this->m_server_list.size()];

	for (size_t i = 0; i < this->m_server_list.size(); i++)
	{
		EV_SET(m_socketEvents, m_server_list.at(i)->getSocket(), EVFILT_READ, EV_ADD, 0, 0, 0);
		stringstream ss;

		kevent(this->m_kq, m_socketEvents, 1, NULL, 0, NULL);
		ss << "Monitoring socket fd: " << this->m_server_list.at(i)->getSocket();
		Logger::log(ss.str(), INFO);
	}
}

server_iterator ServerHandler::m_isSocketFd(const fd file_descriptor)
{
	server_iterator it;
	for (it = this->m_server_list.begin(); it != this->m_server_list.end(); it++)
		if ((*it)->getSocket() == file_descriptor)
			return it;
	return it;
}

void ServerHandler::m_updateEvents()
{
	this->m_new_events = kevent(this->m_kq, NULL, 0, m_events, 1, NULL);

	if (this->m_new_events == -1)
		throw (std::runtime_error("error retrieving new m_events"));
}

void ServerHandler::m_eventLoop()
{
	for (int i = 0; i < this->m_new_events; i++)
	{
		server_iterator	ocurrence;
		Server			*server = NULL;
		const fd		event_fd = m_events[i].ident;

		ocurrence = m_isSocketFd(event_fd);
		if (ocurrence != this->m_server_list.end())
			(*ocurrence)->acceptClient(this->m_active_fds, this->m_kq);
		else if (m_events[i].flags & EV_EOF)
		{
			if (this->m_active_fds.count(event_fd))
				server = this->m_active_fds.find(event_fd)->second;
			else
				server = this->m_active_fds.begin()->second;
			server->disconnectClient(this->m_kq, event_fd);
		}
		else if (m_events[i].filter == EVFILT_READ)
		{
			if (this->m_active_fds.count(event_fd))
				server = this->m_active_fds.find(event_fd)->second;
			else
				server = this->m_active_fds.begin()->second;

			server->message[event_fd].handle_request(event_fd, m_events[i].data);
			if (server->message[event_fd].finishedReading)
				server->enableWrite(this->m_kq, event_fd);
		}
		else if (m_events[i].filter == EVFILT_WRITE)
		{
            if (this->m_active_fds.count(event_fd))
				server = this->m_active_fds.find(event_fd)->second;
            else
				server = this->m_active_fds.begin()->second;

			server->message[event_fd].make_response(event_fd, m_events[i].data);
			server->disableWrite(this->m_kq, event_fd);
			if (server->message[event_fd].getConnectionType() == "close")
			{
				cout << "Getter:" << server->message[event_fd].getConnectionType() << "\n";
				server->disconnectClient(this->m_kq, event_fd);
			}
			if (server->message[event_fd].m_readStatus != Request::CHUNKED_TRANSFER)
				server->message[event_fd].reset();
		}
	}
}
void ServerHandler::mainLoop()
{
	for (;;)
	{
//		Logger::log("New loop", WARNING);
		this->m_updateEvents();
		this->m_eventLoop();
	}
}
