#pragma once
#include <iostream>
#include <asio/include/asio.hpp>

static void Connection_Handler(asio::ip::tcp::acceptor &acceptor, asio::ip::tcp::socket &socket)
{
    acceptor.listen();
    //acceptor.accept();
    asio::ip::tcp::endpoint conn = socket.remote_endpoint();
    std::cout << "Connection reversed <- " << conn.address() << std::endl;
    socket.close();
} 
