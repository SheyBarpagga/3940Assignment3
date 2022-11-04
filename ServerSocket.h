#pragma once
#include "Socket.h"
class ServerSocket
{
public:
	ServerSocket(int port);
	Socket* Accept();
	~ServerSocket();

    int sock;
};

