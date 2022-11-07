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
  if ((rval = read(sock, buf, 1024)) < 0){
    perror("reading socket");
  }else  {
    cout << buf << endl;
//      FileUploadServlet *up = new FileUploadServlet();
//      up->doPost(sock, *buf, *buf1);
      close (sock);
//      printf("%s\n", "The server is printing this because there was a get request!");
//      printf("%s\n",buf);
//      printf("Reading from buffer (on GET request) done\n");
//      int i = 0;
//      while ((rval = read(sock, buf, 1)) == 1) {
//          buf1[i] = buf[0];
//          i++;
////          putchar(buf);  //you can uncomment it to debug
//      }
//      buf1[i] = '\0';
//      close(sock);
//      int nread;
//      char *p = (char*)buf;
//      char *q = (char*)buf + n;
//
//      while(p < q) {
//          if ((nread = read(sock, p, q-p)) < 0) {
//              if(errno == EINTR)
//                  continue;
//              else
//                  return buf;
//          } else if (nread == 0)
//              break;
//          p += nread;
//      }
//      return p - (char*) buf;
//      FileUploadServlet *get = new FileUploadServlet();
//      get->doPost(sock, *buf, *buf);
//      close(sock);
//    printf("%s\n",buf);
  }
	return buf;
}
void Socket::sendResponse(char *res){
int rval;

  if ((rval = write(sock, res, strlen(res))) < 0){
    perror("writing socket");
  }else  {
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
