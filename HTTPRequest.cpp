//
// Created by 16045 on 11/4/2022.
//

#include "HTTPRequest.h"
#include "ServerSocket.h"
#include <stddef.h>
#include <cstring>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <sys/socket.h>

void HTTPRequest::doGet(int sock, char request, char response) {

}

void HTTPRequest::doPost(int sock, char request, char response) {

}


//int main() {
//    char req, res;
//    HTTPRequest *request = new HTTPRequest;
//    request->doGet(req, res);
//}