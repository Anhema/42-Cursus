#ifndef SERVER_HPP
# define SERVER_HPP

# include "../Utilities/Utilities.hpp"
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <iostream>
# include <cstring>
# include <arpa/inet.h>
# include <stdlib.h>
# include <stdio.h>
# include <sstream>
# include <vector>
# include <sys/event.h>
# include <sys/time.h>
# include <fcntl.h>
# include "Message.hpp"
# include "DataContainers.hpp"

class Server {
public:
	Server();
	Server(Data::Server options, int port);
	Server(string ip, int port, string name);
	Server(const Server &obj);
	~Server();

	Server	&operator=(const Server &obj);
    fd		getSocket(void) const;


public:
	static const u_int16_t 	max_listen_queue = 128;
	static const u_int16_t	maxEvents = 1024;
    Message                 message[Server::maxEvents];

private:
	const	string			m_ip;
	const	int 			m_port;
	const	u_int32_t 		m_socketAddress_len;
	const	Data::Server 	m_config;
	struct	sockaddr_in		m_socketAddress;
	struct	kevent			m_read_event;
	struct	kevent			m_write_event;
	fd 						m_socket_fd;

public:
    fd		 	   			acceptClient(std::map<fd, Server *> &socket_map, int kq) const;

public:
	void 					disconnectClient(int kq, const fd client);
	void					enableEvent(int kq, const fd event_fd, struct kevent *k_struct, short event) const;
	void					disableEvent(int kq, const fd event_fd, struct kevent *k_struct, short event) const;
	void					enableWrite(int kq, const fd event_fd) const;
	void					disableWrite(int kq, const fd event_fd) const;

private:
	void	    			m_bindSocket();
	void    				m_startSocket();
	void	    			m_startSocketAddress();
	void 	    			m_startListen();

};

#endif
