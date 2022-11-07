//
// Created by 16045 on 11/4/2022.
//

#include "FileUploadServlet.h"
#include "ServerSocket.h"
#include <stddef.h>
#include <cstring>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <sys/socket.h>
#include <cerrno>
#include <iostream>

using namespace std;
#include <iostream>

using std::cout;
using std::endl;

void FileUploadServlet::doGet(int sock, char request, char response) {
//    ServerSocket *ss = new ServerSocket(8888);
//    if (ss != NULL) {
//        Socket *cs = ss->Accept();
        char arr[]= "HTTP/1.1 200 OK\r\n"
                    "Connection: keep-alive\r\n"
                    "Content-type: text/html\r\n"
                    "\r\n"
                    "<html>\r\n"
                    "<head>\r\n"
                    "<style>@import url('https://fonts.googleapis.com/css2?family=Hind+Siliguri:wght@300;400;500;600;700&display=swap');\n"
                    "\n"
                    "body {\n"
                    "    background-color: #76E9FF;\n"
                    "    font-family: 'Hind Siliguri', sans-serif;\n"
                    "}\n"
                    "\n"
                    "#sessionId {\n"
                    "    text-align: right;\n"
                    "    font-weight: bold;\n"
                    "}\n"
                    "\n"
                    "#signInBtn {\n"
                    "    background-color: #52BBE7;\n"
                    "    border-radius: 5px;\n"
                    "    padding: 10px 30px;\n"
                    "    margin: 8px 0;\n"
                    "    max-width: 30%;\n"
                    "    font-size: 24px;\n"
                    "    border-style: solid;\n"
                    "    transition: all 0.5s;\n"
                    "}\n"
                    "#signUpBtn {\n"
                    "    background-color: #52BBE7;\n"
                    "    border-radius: 5px;\n"
                    "    padding: 10px 15px;\n"
                    "    margin: 8px 0;\n"
                    "    max-width: 30%;\n"
                    "    font-size: 24px;\n"
                    "    border-style: solid;\n"
                    "    transition: all 0.5s;\n"
                    "}\n"
                    "\n"
                    "#noAccount {\n"
                    "    text-align: center;\n"
                    "    margin-bottom: 0px;\n"
                    "}\n"
                    "\n"
                    "span {\n"
                    "    color: #004489;\n"
                    "}\n"
                    "\n"
                    "form {\n"
                    "    text-align: center;\n"
                    "}\n"
                    "\n"
                    ".mainBtn {\n"
                    "    background-color: #52BBE7;\n"
                    "    border-radius: 5px;\n"
                    "    padding: 30px;\n"
                    "    margin: 8px 0;\n"
                    "    width: 50%;\n"
                    "    font-size: 24px;\n"
                    "    border-style: solid;\n"
                    "    transition: all 0.5s;\n"
                    "}\n"
                    "\n"
                    ".mainBtn:hover, #signInBtn:hover, #signUpBtn:hover {\n"
                    "    background-color: white;\n"
                    "    transform: scale(1.2);\n"
                    "    transition: all 0.3s;\n"
                    "}</style>"
                    "<title>Hello, world!</title>\r\n"
                    "</head>\r\n"
                    "<body>\r\n"
                    "<h1>Upload file</h1>"
                    "<form method=\"POST\" type=\"multipart/form-data\">"
                    "<input type=\"file\" name=\"fileName\"/><br/><br/>"
                    "            Caption: <input type=\"text\" name=\"caption\"<br/><br/>"
                    "            <br />"
                    "            Date: <input type=\"date\" name=\"date\"<br/><br/>"
                    "            <br />"
                    "            <input type=\"submit\" value=\"Submit\"/>"
                    "            </form>"
                    "            </body></html>";

        int send_res = write(sock,arr,strlen(arr));
   // }
}

void FileUploadServlet::doPost(int sock, char *request, char *response) {

    cout << "bytes" << strlen(request) <<endl;
//    doGet(sock, *request, *response);
}


int FileUploadServlet::readn(int fd, void *buf, int n) {
    int nread;
    char *p = (char*)buf;
    char *q = (char*)buf + n;

//    while(p < q) {
//        if ((nread = read(fd, p, q-p)) < 0) {
//            if(errno == EINTR)
//                continue;
//            else
//                return -1;
//        } else if (nread == 0)
//            break;
//        p += nread;
//    }
    close (fd);
    return p - (char*) buf;
    // Upon submitting form, POST method is invoked.
    // Submitting the form should save the file (and all other form data i.e caption and date) in the server's own
    // internal file system. The additional date will be saved in the title of the file
    cout << "The File Upload Servlet is processing a POST request" << endl;
}