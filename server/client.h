#pragma once
#include <asio.hpp>
#include <chrono>

class client
{
public:
    client(asio::ip::tcp::endpoint endpoint);
    client(client& clients) = delete;
private:
    std::chrono::steady_clock Stamp;
    asio::ip::tcp::endpoint Endpoint;
};