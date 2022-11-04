cmake_minimum_required(VERSION 3.21)
project(Assignment3_3940)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment3_3940
        main.cpp
        ServerSocket.cpp
        ServerSocket.h
        Socket.cpp
        Socket.h
        Thread.cpp
        Thread.h
        SimpleThread.cpp
        SimpleThread.h Servlet.h HTTPResponse.cpp HTTPResponse.h HTTPRequest.cpp HTTPRequest.h FileUploadServlet.cpp FileUploadServlet.h)
