//
// Created by 16045 on 11/2/2022.
//

#ifndef MAIN_CPP_SERVLET_H
#define MAIN_CPP_SERVLET_H


class Servlet {
    virtual void doGet(char request, char response);
    virtual void doPost(char request, char response);
};


#endif //MAIN_CPP_SERVLET_H
