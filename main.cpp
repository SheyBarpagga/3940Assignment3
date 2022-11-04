#include "Socket.h"
#include "ServerSocket.h"
#include <stddef.h>
#include <cstring>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>

int main() {
  ServerSocket *ss = new ServerSocket(8888);
	if (ss != NULL) {
        while(true) {
            Socket *cs = ss->Accept();
            char *req = cs->getRequest();
            char *res = new char(50);
            cs->sendResponse(res);
        }

//        char arr[]= "HTTP/1.1 200 OK\r\n"
//                    "Connection: keep-alive\r\n"
//                    "Content-type: text/html\r\n"
//                    "\r\n"
//                    "<html>\r\n"
//                    "<head>\r\n"
//                    "<style>@import url('https://fonts.googleapis.com/css2?family=Hind+Siliguri:wght@300;400;500;600;700&display=swap');\n"
//                    "\n"
//                    "body {\n"
//                    "    background-color: #76E9FF;\n"
//                    "    font-family: 'Hind Siliguri', sans-serif;\n"
//                    "}\n"
//                    "\n"
//                    "#sessionId {\n"
//                    "    text-align: right;\n"
//                    "    font-weight: bold;\n"
//                    "}\n"
//                    "\n"
//                    "#signInBtn {\n"
//                    "    background-color: #52BBE7;\n"
//                    "    border-radius: 5px;\n"
//                    "    padding: 10px 30px;\n"
//                    "    margin: 8px 0;\n"
//                    "    max-width: 30%;\n"
//                    "    font-size: 24px;\n"
//                    "    border-style: solid;\n"
//                    "    transition: all 0.5s;\n"
//                    "}\n"
//                    "#signUpBtn {\n"
//                    "    background-color: #52BBE7;\n"
//                    "    border-radius: 5px;\n"
//                    "    padding: 10px 15px;\n"
//                    "    margin: 8px 0;\n"
//                    "    max-width: 30%;\n"
//                    "    font-size: 24px;\n"
//                    "    border-style: solid;\n"
//                    "    transition: all 0.5s;\n"
//                    "}\n"
//                    "\n"
//                    "#noAccount {\n"
//                    "    text-align: center;\n"
//                    "    margin-bottom: 0px;\n"
//                    "}\n"
//                    "\n"
//                    "span {\n"
//                    "    color: #004489;\n"
//                    "}\n"
//                    "\n"
//                    "form {\n"
//                    "    text-align: center;\n"
//                    "}\n"
//                    "\n"
//                    ".mainBtn {\n"
//                    "    background-color: #52BBE7;\n"
//                    "    border-radius: 5px;\n"
//                    "    padding: 30px;\n"
//                    "    margin: 8px 0;\n"
//                    "    width: 50%;\n"
//                    "    font-size: 24px;\n"
//                    "    border-style: solid;\n"
//                    "    transition: all 0.5s;\n"
//                    "}\n"
//                    "\n"
//                    ".mainBtn:hover, #signInBtn:hover, #signUpBtn:hover {\n"
//                    "    background-color: white;\n"
//                    "    transform: scale(1.2);\n"
//                    "    transition: all 0.3s;\n"
//                    "}</style>"
//                    "<title>Hello, world!</title>\r\n"
//                    "</head>\r\n"
//                    "<body>\r\n"
//                    "<h1>Upload file</h1>"
//                    "<form method=\"POST\" type=\"multipart/form-data\">"
//                    "<input type=\"file\" name=\"fileName\"/><br/><br/>"
//                    "            Caption: <input type=\"text\" name=\"caption\"<br/><br/>"
//                    "            <br />"
//                    "            Date: <input type=\"date\" name=\"date\"<br/><br/>"
//                    "            <br />"
//                    "            <input type=\"submit\" value=\"Submit\"/>"
//                    "            </form>"
//                    "            </body></html>";
//
//    int send_res = send(cs->getSock(),arr,strlen(arr),0);
//    char buf[1024];
//    int rval;
//    int i;
//    listen(cs->getSock(), 1);
//    while(1){
//        Socket *msgsock = ss->Accept();
//        if (msgsock->getSock() == -1) {
//            perror("accept");
//        }
//        if (fork() == 0) {
//            if ((rval = read(msgsock->getSock(), buf, 1024)) < 0){
//                perror("reading socket");
//            }else {
//                send(cs->getSock(),"",strlen(nullptr),0);
//                send(msgsock->getSock(),arr,strlen(arr),0);
//            }
//            close (msgsock->getSock());
//        }close (cs->getSock());
//    }
    }

    return 1;
}
