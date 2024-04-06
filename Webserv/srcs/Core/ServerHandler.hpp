#ifndef SERVER_HANDLER_HPP
# define SERVER_HANDLER_HPP

# include "../Utilities/Utilities.hpp"
# include "../Logger/Logger.hpp"
# include "Server.hpp"
# include "DataContainers.hpp"


# define SERVER_COUNT 3
# define LOCALHOST "0.0.0.0"
# define DEFAULT_NAME "Server_default"
# define START_PORT 8080


typedef std::vector<Server *>::iterator server_iterator;

class ServerHandler {

public:
	ServerHandler(std::vector<Data::Server>configurations);
	ServerHandler(int server_count);
	~ServerHandler();
	ServerHandler(ServerHandler const &rhs);

	ServerHandler &operator=(ServerHandler const &rhs);

    void									mainLoop(void);

private:
	void 									startServer(Data::Server configuration);
	void									m_startKqueue(void);
	void									m_monitorSockets(void);
	void 									m_eventLoop(void);
	void									m_updateEvents(void);
	server_iterator 						m_isSocketFd(const fd file_descriptor);

private:
	std::vector<Server *>					m_server_list;
	struct kevent                  			*m_socketEvents;
	std::map<fd, Server *>			        m_active_fds;
	struct kevent							m_events[Server::maxEvents];

private:
    int                                     m_new_events;
	int			 							_server_count;
	int										m_kq;

};


#endif
