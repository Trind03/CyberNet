#pragma once
#include <asio.hpp>
#include "../internet_computer.h"

class client : public internet_computer
{
public:
    client(client&) = delete;
    client() = delete;
    client(bool title,asio::ip::address_v4&& binding_addr,const unsigned int&& port);
    std::chrono::seconds timeout(std::chrono::seconds* ptr);

    void start();
    asio::error_code _Error;
    const unsigned int _Port;
    asio::io_context _Io_context;
    asio::ip::tcp::socket _Sock;
    asio::ip::tcp::endpoint _Endpoint;
    asio::ip::address_v4 _Binding_addr;
    bool _Running;
};