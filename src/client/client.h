#pragma once
#include <asio.hpp>

class client
{
public:
    client(client&) = delete;
    client() = delete;
    client(asio::ip::address&& binding_addr,uint8_t&& port);

private:
    asio::error_code _Error;
    asio::io_context _Io_context;
    asio::ip::tcp::socket _Sock;
    asio::ip::tcp::endpoint _Endpoint;
    const uint8_t _Port;
    const asio::ip::address _Binding_addr;
    bool _Running;
};