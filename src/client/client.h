#pragma once
#include <asio.hpp>

class client
{
public:
    client(client&) = delete;
    client() = delete;
    client(asio::ip::address&& binding_addr,uint8_t&& port);
    
private:
    asio::io_context _Io_context;
    asio::ip::tcp::socket _Sock;
    asio::error_code _Error;
    const uint8_t _Port;
    const asio::ip::address _Binding_addr;
    bool running;
};