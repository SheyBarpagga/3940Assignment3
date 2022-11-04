//
// Created by 16045 on 11/4/2022.
//

#ifndef MAIN_CPP_FILEUPLOADSERVLET_H
#define MAIN_CPP_FILEUPLOADSERVLET_H


class FileUploadServlet {


public:
    void doGet(int sock, char request, char response);
    void doPost(int sock, char request, char response);
};


#endif //MAIN_CPP_FILEUPLOADSERVLET_H
