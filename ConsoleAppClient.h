// Created by rodri on 11/5/2022.
//
#pragma once


// a C++ based console application that uploads an image as multipart data along with other form data
// e.g. date and keyword via the upload Servlet.

//Parse JSON in incoming response from server and print out listing on screen

class ConsoleAppClient {

public:
    void doGet(int sock, char request, char response);
    void doPost(int sock, char request, char response);

};



