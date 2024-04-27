#pragma once
#include <asio/include/asio.hpp>
#include <thread>
#include <functional>
#include "utils.hpp"
#include "session.h"
#include "command.h"

std::function<void()> boot_message = []()
{
    std::cout << "\t\t\t" << "***** Prototype Of CyberNet Software *****" << "\n\n\n";
};

int server()
{
    boot_message();
    session_details session_details(5554); 
    command command(&session_details);

    asio::io_context io_context;
    asio::ip::tcp::endpoint con_details(asio::ip::tcp::v4(),session_details.port);
    asio::ip::tcp::acceptor acceptor(io_context,con_details);
    asio::ip::tcp::socket socket(io_context);

    std::thread command_validator = std::thread(&command::command_handler, &command);

    while(true)
    {
        Connection_Handler(acceptor,socket);
    }
    command_validator.join();
    return EXIT_SUCCESS;
}