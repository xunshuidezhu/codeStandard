#include "tcp_server.h"

using namespace std;

template <class T>
void tcp_server<T>::connect()
{
    clinet_addr_size = sizeof(clinet_addr);
    while (1) {
        client_fd = accept(server_fd, (sockaddr*)clinet_addr, &clinet_addr_size);
        is_correct(client_fd);
        while ((str_len = read(client_fd, message, BUFFERSIZE)) != 0) {
            write(clientSock, message, str_len);
        }
        
    }

}

template <class T>
void tcp_server<T>::init()
{
    server_fd  = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server_addr, sizeof(server_addr));
    is_correct(server_fd);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    is_correct(server_addr);
    bind(server_fd, (sockaddr*)&server_addr,sizeof(server_addr));
    is_correct(server_fd);
    listen(server_fd, listen_queue);
    is_correct(server_fd);
}

template <class T>
bool tcp_server<T>::is_correct(T fd)
{
    if (fd < 0) {
        cout << fd << "need > 0" << endl;
        abort();
        return false;
    }
    return true;

}

template <class T>
void tcp_server<T>::close()
{
    close(client_fd);
    close(server_fd);
}

template <class T>
tcp_server<T>::~tcp_server()
{
    close();
}