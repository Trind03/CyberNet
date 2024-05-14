#include <iostream>
#include <asio/include/asio.hpp>
#include "title.hpp"
static bool running = true;
int client()
{
    asio::ip::address_v4 IPV4 = asio::ip::address_v4();
    constexpr int target_port = 5554;    

    asio::error_code error;
    asio::io_context io_context;
    asio::ip::tcp::endpoint endpoint(IPV4,target_port);
    asio::ip::tcp::socket sock(io_context);

    while(running)
    {}

    return 0;
}