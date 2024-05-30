#pragma once
#include <vector>
#include <asio/include/asio.hpp>


class server
{
public:
    server(unsigned short&& port, const char*&& filename);
    server(server&) = delete;
    void start(server* Server);
private:
    /* assets */
    asio::io_context Io_context;
    asio::ip::tcp::endpoint Endpoint;
    asio::ip::tcp::acceptor Acceptor;
    asio::ip::tcp::socket Sock;
    asio::error_code Error;
    unsigned short Port;
};