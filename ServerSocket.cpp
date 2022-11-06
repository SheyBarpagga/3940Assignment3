#include "ServerSocket.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <stdio.h>

#include <iostream>

using namespace std;

ServerSocket::ServerSocket(int port)
{
    sock = socket (AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(8888);
    //  Uncomment the call to inet_aton when we want to connect to a specific IP address (instead of localhost).
    //  Make sure to put in the right IP address - 192.168.1.128 is just a placeholder
    //  inet_aton("192.168.1.128", &server.sin_addr);


    int option;
    getsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &option, reinterpret_cast<socklen_t *>(sizeof(option)));
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror ("binding stream socket");
    }

    getsockname( sock, (struct sockaddr *) &server,(socklen_t *)sizeof server);
    cout << "listening" << endl;
    listen(sock, 5);

}

Socket* ServerSocket::Accept()
{
	sockaddr_in localAddr, remoteAddr;
	int addrLen = sizeof (remoteAddr);
	int cSock = accept(sock, (struct sockaddr *)&remoteAddr, &addrLen);
	Socket *cs = new Socket(cSock);
	return cs;
}
ServerSocket::~ServerSocket()
{
}
