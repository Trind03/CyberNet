#pragma once
#include <asio.hpp>
#include <chrono>

class client
{
public:
    client(client& clients) = delete;
    std::chrono::steady_clock Stamp;
    asio::ip::tcp::endpoint Endpoint;
};