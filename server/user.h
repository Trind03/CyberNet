#pragma once
#include <asio/include/asio.hpp>

struct user
{
    user::user(asio::ip::tcp::endpoint ip, int id);
    int ID;
    asio::ip::tcp::endpoint IPV4;
};
