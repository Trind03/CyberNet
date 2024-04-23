#pragma once
#include <iostream>
#include <thread>
#include <asio/include/asio.hpp>
#include "utils.hpp"
#include "session.h"
#include "command.h"


int server()
{
    std::thread command_validator;
    session_details session_details(5554); 
    command command(&session_details);

    asio::io_context io_context;
    asio::ip::tcp::endpoint con_details(asio::ip::tcp::v4(),session_details.port);
    asio::ip::tcp::acceptor acceptor(io_context,con_details);
    asio::ip::tcp::socket socket(io_context);

    command_validator = std::thread(&command::command_handler, &command);

    while(true)
    {
        Connection_Handler(acceptor,socket);
        std::cout << std::endl << "Connection established" << std::endl;
    }
    command_validator.join();
    return EXIT_SUCCESS;
}