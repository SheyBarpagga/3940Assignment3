#include "Socket.h"
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
    printf("%s\n",buf);
  }
	return buf;
}
void Socket::sendResponse(char *res){
int rval;

  if ((rval = write(sock, res, strlen(res))) < 0){
    perror("writing socket");
  }else  {
      char arr[]= "HTTP/1.1 200 OK\r\n"
                "Connection: close\r\n"
                "Content-type: text/html\r\n"
                "\r\n"
                "<html>\r\n"
                "<head>\r\n"
                "<title>Hello, world!</title>\r\n"
                "</head>\r\n"
                "<body>\r\n"
                "<h1>Hello, world!</h1>\r\n"
                "</body>\r\n"
                "</html>\r\n\r\n";
//      write(sock, arr, strlen(res));
//  printf(arr);
//    int send_res = send(sock,arr,strlen(arr),0);
//    printf("%s\n",arr);
  }

	return;
}


Socket::~Socket()
{
}

int Socket::getSock() {
    return sock;
}
