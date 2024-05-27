#pragma once
#include <asio/include/asio.hpp>
#include <thread>
#include <memory>
#include "utils.hpp"
#include "command.h"
#include "user.h"
#include "title.hpp"
#include <winsock.h>

using namespace std;
using namespace asio::ip;

constexpr short port = 5554;

constexpr const char* filename = "title.dat";

int main()
{
    thread t_boot_message = thread(boot_message_server,filename);
    const tcp IPV4 = tcp::v4();
    std::vector<user>users{};
    t_boot_message.join();


    command command(&users);
    std::thread t_command_validator = thread(&command::command_handler,&command);

    asio::io_context io_context;

    tcp::endpoint endpoint(tcp::v4(),port);
    tcp::acceptor acceptor(io_context,endpoint);
    tcp::socket socket(io_context);


    Connection_Handler(acceptor,socket);
    t_command_validator.join();
    

    return EXIT_SUCCESS;
}