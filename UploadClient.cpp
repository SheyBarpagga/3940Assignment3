#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "UploadClient.h"
#include "Socket.h"
#include <iostream>
#include <ostream>
#include <fstream>

using std::cout;
using std::endl;
using namespace std;

void UploadClient::getInput(){
    // If we wrap this in getline, it will be able to accept spaces
    cout << "Enter file path: " << endl;
    cin >> filePath;
    cout << "Enter date for file: " << endl;
    cin >> fileDate;
    cout << "Enter keyword for file: " << endl;
    cin >> keyWord;
    cout << "Enter caption for file: " << endl;
    cin.ignore();
    getline(cin, fileCaption);
}

void UploadClient::doPost(){
    int sock;
    struct sockaddr_in server;
    char buf[1024];
    struct hostent *hp;
    char *host = "127.0.0.1";
    int rval;

    sock = socket (AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error opening stream socket");
    }

    bzero(&server, sizeof(server));
    hp = gethostbyname("localhost");
    bcopy((char*)hp->h_addr, (char*)&server.sin_addr, hp->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server))<0){
        perror("Error connecting");
    }

    DIR *directory;
    directory = opendir(filePath.c_str());
    ifstream myFile;
    myFile.open(filePath, ios::binary);

    string writer;
    string newLine = "\r\n";

    writer.append("-----------------------------").append(newLine);
    writer.append("File Uploaded: ").append(newLine).append(newLine);
    writer.append("filename=\"").append("File").append("\"").append(newLine);

    writer.append("-----------------------------").append(newLine);
    writer.append("File Date: ").append(newLine);
    writer.append(newLine).append(fileDate).append(newLine);

    writer.append("-----------------------------").append(newLine);
    writer.append("File Keyword: ").append(newLine);
    writer.append(newLine).append(keyWord).append(newLine);

    writer.append("-----------------------------").append(newLine);
    writer.append("File Caption: ").append(newLine);
    writer.append(newLine).append(fileCaption).append(newLine);
    writer.append("-----------------------------").append(newLine);

    cout << writer << endl;

    if((rval = write(sock, "Hello server, from client", 1024)) < 0){
        perror("Error writing to sock");
    }
    close(sock);
}

int main(){
    UploadClient *c = new UploadClient();
    c->getInput();
    c->doPost();
}