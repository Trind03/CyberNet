#pragma once
#include <asio/include/asio.hpp>


class server
{
public:
    explicit server(unsigned short port,const char* filename);
    server(server&) = delete;
    int start(std::shared_ptr<server>Server);
    void stop();
    bool get_running_status();
private:
    /* assets */
    asio::io_context Io_context;
    asio::ip::tcp::endpoint Endpoint;
    asio::ip::tcp::acceptor Acceptor;
    asio::ip::tcp::socket Sock;
    asio::error_code Error;
    unsigned short Port;
    bool Running;
};