#pragma once
#include <asio/include/asio.hpp>

void connection_handler(asio::ip::tcp::acceptor &acceptor, asio::ip::tcp::socket &socket)
{
    acceptor.accept();
    socket.close();
}