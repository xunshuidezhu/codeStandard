#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "uncopyable.h"

#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define BIND_PORT 8888

template <class T>
class tcp_server : public uncopyable
{
public:
    tcp_server(int _fd) : server_fd(_fd) {}
    ~tcp_server();
    void close();
    void init();
    void connect();
    bool is_correct(T);
    void bind();
    
private:
    int server_fd, client_fd;
    sockaddr_in server_addr, clinet_addr;
    const int PORT = BIND_PORT;
    int listen_queue = 5;
    socklen_t clinet_addr_size;
    char* message;
};

#endif