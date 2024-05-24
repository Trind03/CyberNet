#pragma once
#include <chrono>
#include <asio/include/asio.hpp>

class Net_conn// : public std::enable_shared_from_this<Net_conn>
{
public:
    Net_conn();
    Net_conn(Net_conn&) = delete;
    ~Net_conn();

    asio::ip::tcp::socket& get_socket();

    void broadcast();

private:
    asio::ip::tcp::socket* socket;
    asio::steady_timer* broadcast_interval;
};
