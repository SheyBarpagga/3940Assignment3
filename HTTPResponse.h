//
// Created by 16045 on 11/2/2022.
//

#ifndef MAIN_CPP_HTTPRESPONSE_H
#define MAIN_CPP_HTTPRESPONSE_H

#include "Servlet.h"

class HTTPResponse : public Servlet{
    void doPost(int sock, char request, char response) override;
    void doGet(int sock, char request, char response) override;
};


#endif //MAIN_CPP_HTTPRESPONSE_H
