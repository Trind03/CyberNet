#include <iostream>
#include <thread>
#include <asio/asio/include/asio.hpp>
#include "title.hpp"


static bool running = true;
int main()
{
    const char* filename = "title.dat";
    std::thread title_client = std::thread(boot_message_client,filename);
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