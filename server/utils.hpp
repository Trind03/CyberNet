#pragma once
#include <iostream>
#include <asio/include/asio.hpp>

static void Connection_Handler(asio::ip::tcp::acceptor &acceptor, asio::ip::tcp::socket &socket)
{
    acceptor.accept(socket);
    asio::ip::tcp::endpoint conn = socket.remote_endpoint();
    asio::ip::address client_addr = conn.address();
    socket.close();
} 
