#pragma once
#include <asio/include/asio.hpp>
#include <thread>
#include <memory>
#include "utils.hpp"
#include "session.h"
#include "command.h"
#include "user.h"
#include "title.hpp"

int server()
{
    std::vector<user>users {};
    std::thread T_boot_message = std::thread(boot_message,"title.txt");
    asio::io_context io_context;
    command command(&users);

    asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(),5554);
    asio::ip::tcp::acceptor acceptor(io_context,endpoint);

    T_boot_message.join();
    std::thread T_command_validator = std::thread(&command::command_handler,&command);

    while(true)
    {
        asio::ip::tcp::socket socket(io_context);
        acceptor.accept();
        std::cout << socket.remote_endpoint() << std::endl;
    }

    T_command_validator.join();
    return EXIT_SUCCESS;
}