#pragma once
#include <asio/include/asio.hpp>
#include <thread>
#include <functional>
#include "utils.hpp"
#include "session.h"
#include "command.h"
#include "user.h"
std::function<void()> boot_message = []()
{
    std::cout << "\t\t\t" << "***** Prototype Of CyberNet Software *****" << "\n\n\n";
};

int server()
{
    std::thread T_boot_message = std::thread(boot_message);
    session_details session_details(5554); 
    command command(&session_details);

    asio::io_context io_context;
    asio::ip::tcp::endpoint con_details(asio::ip::tcp::v4(),session_details.port);
    asio::ip::tcp::acceptor acceptor(io_context,con_details);
    asio::ip::tcp::socket socket(io_context);

    T_boot_message.join();
    std::thread T_command_validator = std::thread(&command::command_handler, &command);

    while(true)
    {
        Connection_Handler(acceptor,socket);
    }
    

    T_command_validator.join();
    socket.close();
    return EXIT_SUCCESS;
}