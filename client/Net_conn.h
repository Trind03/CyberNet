#pragma once
#include <chrono>
#include <asio.hpp>

struct Net_conn : public std::enable_shared_from_this<Net_conn>
{
    
    Net_conn(asio::io_context& io_context);
    ~Net_conn();

    asio::ip::tcp::socket& get_socket();

    void broadcast();
    asio::ip::tcp::socket sock;
    asio::steady_timer ping_timer;
};
