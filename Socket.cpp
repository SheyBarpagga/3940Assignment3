#include "Socket.h"
#include "FileUploadServlet.h"
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <cerrno>
#include <iostream>
using namespace std;
Socket::Socket(int sock)
{
	this->sock = sock;
}
char* Socket::getRequest()
{
  int rval;      char buf1[526336];      char buf[1];
//    char *buf = new char[1024];
  if ((rval = read(sock, buf1, 526336)) < 0){
    perror("reading socket");
  }else  {
      FileUploadServlet *upload = new FileUploadServlet();
      char req;
      upload->doGet(sock, req, *buf);
      cout << buf1 << endl;
      upload->doPost(sock, buf1, buf);
      close(sock);
//    printf("%s\n",buf);
  }
	return buf;
}
void Socket::sendResponse(char *res) {
    int rval;

    if ((rval = write(sock, res, strlen(res))) < 0) {
        perror("writing socket");
    } else {
        printf("%s\n", "The server is sending a response!");
        FileUploadServlet *upload = new FileUploadServlet();
        char req;
        upload->doGet(sock, req, *res);
        close(sock);
        return;
    }
}

Socket::~Socket()
{
}

int Socket::getSock() {
    return sock;
}
