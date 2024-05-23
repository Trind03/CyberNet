#pragma once
#include <chrono>
#include <asio.hpp>

struct heartbeat_tx : public std::enable_shared_from_this<heartbeat_tx>
{
    
    heartbeat_tx(asio::io_context& io_context);
    ~heartbeat_tx();

    asio::ip::tcp::socket& get_socket();

    void broadcast();
    asio::ip::tcp::socket sock;
    asio::steady_timer ping_timer;
};
