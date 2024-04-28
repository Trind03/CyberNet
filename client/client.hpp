#include <iostream>
#include <asio/include/asio.hpp>

int client()
{
    constexpr const char* target_ip = "192.168.86.55";
    constexpr int target_port = 5554;    

    asio::error_code error;
    asio::io_context io_context;
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address(target_ip,error),target_port);
    asio::ip::tcp::socket sock(io_context);

    sock.connect(endpoint,error);
    io_context.run();
    return 0;
}