//
// Created by 16045 on 11/4/2022.
//

#ifndef MAIN_CPP_HTTPREQUEST_H
#define MAIN_CPP_HTTPREQUEST_H


#include "Servlet.h"

class HTTPRequest : public Servlet{
    void doPost(int sock, char request, char response) override;

public:
    void doGet(int sock, char request, char response) override;
};


#endif //MAIN_CPP_HTTPREQUEST_H
