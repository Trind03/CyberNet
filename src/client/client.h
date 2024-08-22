#pragma once
#include <iostream>
#include <asio.hpp>

class client
{
public:


private:
    asio::io_context io_context;
    asio::ip::tcp::endpoint endpoint;
    asio::ip::tcp::socket Sock;
    asio::error_code error;
};