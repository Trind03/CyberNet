#pragma once
#include <chrono>
#include <asio.hpp>

class client
{
public:
    client();
    client(client& _client) = delete;
    ~client();

    asio::ip::tcp::socket* get_socket();

    void broadcast();

private:
    asio::io_context *Io_context;
    asio::ip::tcp::socket* sock;
    asio::steady_timer* broadcast_interval;
};
