#pragma once
#include <chrono>
#include <asio.hpp>
#include <chrono>

class client
{
public:
    client();
    ~client();
    client(client& _client) = delete;
    void reset_timer();
    std::chrono::steady_clock get_last_ping() const;
    asio::ip::tcp::endpoint get_endpoint() const;

    void broadcast();

private:
    asio::io_context Io_context;
    asio::ip::tcp::endpoint Endpoint;
    std::chrono::steady_clock last_response;
};
