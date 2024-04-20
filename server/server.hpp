#pragma once
#include <iostream>
#include <asio/include/asio.hpp>
#include "utils.hpp"
#include "session.h"

int server()
{
    static session_details session_details(5554); 
    asio::io_context io_context;
    asio::ip::tcp::endpoint con_details(asio::ip::tcp::v4(),session_details.port);
    asio::ip::tcp::acceptor acceptor(io_context,con_details);

    while(true)
    {
        asio::ip::tcp::socket socket(io_context);
        connection_handler(acceptor,socket);
        std::cout << "Connection established" << std::endl;

    }
    return EXIT_SUCCESS;
}