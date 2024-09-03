#pragma once
#include <asio.hpp>

class client
{
public:
    client(client&) = delete;
    client() = delete;
    client(bool title,asio::ip::address&& binding_addr,const unsigned int&& port);

    asio::error_code _Error;
    const unsigned int _Port;
    asio::io_context _Io_context;
    asio::ip::tcp::socket _Sock;
    asio::ip::tcp::endpoint _Endpoint;
    const asio::ip::address _Binding_addr;
    bool _Running;
};