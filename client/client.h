#pragma once
#include <chrono>
#include <asio.hpp>

class Net_com : public std::enable_shared_from_this<Net_com>
{
public:
    Net_com();
    Net_com(Net_com&) = delete;
    ~Net_com();

    asio::ip::tcp::socket* get_socket();

    void broadcast();

private:
    asio::ip::tcp::socket* sock;
    asio::steady_timer* broadcast_interval;
};
