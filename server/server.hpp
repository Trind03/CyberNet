#pragma once
#include <iostream>
#include <asio/include/asio.hpp>
#include <thread>
#include "utils.hpp"
#include "session.h"
#include "command.h"


int server()
{
    static session_details session_details(5554); 
    //command command(&session_details);

    asio::io_context io_context;
    asio::ip::tcp::endpoint con_details(asio::ip::tcp::v4(),session_details.port);
    asio::ip::tcp::acceptor acceptor(io_context,con_details);
    // std::thread command_validator();
    while(true)
    {
        //command.command_handler();
        asio::ip::tcp::socket socket(io_context);
        connection_handler(acceptor,socket);
        std::cout << "Connection established" << std::endl;
        // command_validator.join();
    }
    return EXIT_SUCCESS;
}