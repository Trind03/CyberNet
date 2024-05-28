#pragma once
#include <vector>
#include <asio/include/asio.hpp>


class server
{
    server();


    /* assets */
    asio::io_context io_context;
    asio::ip::tcp::endpoint endpoint;
    asio::ip::tcp::acceptor acceptor;
    asio::ip::tcp::socket sock;
};