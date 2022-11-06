#include "Socket.h"
#include "FileUploadServlet.h"
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

Socket::Socket(int sock)
{
	this->sock = sock;
}
char* Socket::getRequest()
{
  int rval;
  char *buf = new char[1024];

  if ((rval = read(sock, buf, 1024)) < 0){
    perror("reading socket");
  }else  {
      printf("%s\n", "The server is printing this because there was a get request!");
    printf("%s\n",buf);
  }
	return buf;
}
void Socket::sendResponse(char *res){
int rval;

//  if ((rval = write(sock, res, strlen(res))) < 0){
//    perror("writing socket");
//  }else  {
    printf("%s\n", "The server is sending a response!");
      FileUploadServlet *upload = new FileUploadServlet();
      char req;
      upload->doGet(sock, req, *res);
    close (sock);
	return;
}


Socket::~Socket()
{
}

int Socket::getSock() {
    return sock;
}
