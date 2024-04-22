#pragma once
#include <iostream>
#include <thread>
#include <asio/include/asio.hpp>
#include "utils.hpp"
#include "session.h"
#include "command.h"
#include <memory>
void func()
{
    for(int i = 1; i == 1;)
    std::cout << "Test" << std::endl;
}

int server()
{
    session_details session_details(5554); 
    command command(&session_details);

    asio::io_context io_context;
    asio::ip::tcp::endpoint con_details(asio::ip::tcp::v4(),session_details.port);
    asio::ip::tcp::acceptor acceptor(io_context,con_details);
    while(true)
    {
        //std::thread command_validator(&command::command_handler);
        //command.command_handler();
        asio::ip::tcp::socket socket(io_context);
        Connection_Handler(acceptor,socket);
        std::cout << "Connection established" << std::endl;
        //command_validator.join();
    }
    return EXIT_SUCCESS;
}