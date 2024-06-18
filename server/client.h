#pragma once
#include <asio.hpp>
#include <chrono>

class client
{
public:
    client(asio::ip::tcp::endpoint endpoint);
    client(client& clients) = delete;
    float calculate_time();
    void reset();
private:
    std::chrono::system_clock::time_point time_stamp;
    asio::ip::tcp::endpoint Endpoint;
};