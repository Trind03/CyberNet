#pragma once
#include <asio/include/asio.hpp>
#include <thread>
#include <memory>
#include "utils.hpp"
#include "command.h"
#include "user.h"
#include "title.hpp"

constexpr const char* filename = "title.dat";

int server()
{
    std::thread T_boot_message = std::thread(boot_message,filename);
    const asio::ip::tcp IPV4 = asio::ip::tcp::v4();
    std::vector<user>users{};
    T_boot_message.join();

    command command(&users);
    std::thread T_command_validator = std::thread(&command::command_handler,&command);

    asio::io_context io_context;

    asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(),5554);
    asio::ip::tcp::acceptor acceptor(io_context,endpoint);

    
    while(true)
    {
        asio::ip::tcp::socket socket(io_context);
        acceptor.accept();
        socket.close();
    }
    



    T_command_validator.join();
    return EXIT_SUCCESS;
}