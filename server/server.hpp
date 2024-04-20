#pragma once
#include <iostream>
#include <asio/include/asio.hpp>
#include "utils.hpp"
#include <thread>
constexpr int port = 5554;
int server()
{
    asio::io_context io_context;
    asio::ip::tcp::endpoint con_details(asio::ip::tcp::v4(),port);
    asio::ip::tcp::acceptor acceptor(io_context,con_details);

    while(true)
    {
        asio::ip::tcp::socket socket(io_context);
        std::thread thread(, socket);


        socket.close();
    }
}