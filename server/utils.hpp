#pragma once
#include <asio/include/asio.hpp>

static void Connection_Handler(asio::ip::tcp::acceptor &acceptor, asio::ip::tcp::socket &socket)
{
    
    acceptor.accept();
    socket.close();
} 
