#include <iostream>
#include <asio/include/asio.hpp>

int client()
{
    asio::ip::address_v4 IPV4 = asio::ip::address_v4();
    constexpr int target_port = 5554;    

    asio::error_code error;
    asio::io_context io_context;
    asio::ip::tcp::endpoint endpoint(IPV4,target_port);
    asio::ip::tcp::socket sock(io_context);

    sock.connect(endpoint,error);

    if(!error)
    {
        std::cout << "Connected!" << std::endl;
    }

    else
    {
        std::cout << "Connection failed" << " - "  << std::endl;
    }
    io_context.run();
    return 0;
}