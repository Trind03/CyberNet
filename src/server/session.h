#pragma once
#include <asio.hpp>
#include <chrono>

class session
{
public:
    session(asio::ip::tcp::endpoint &&endpoint);
    //session(session& Session) = delete;
    float calculate_time();
    void reset();
private:
    std::chrono::system_clock::time_point time_stamp;
    asio::ip::tcp::endpoint Endpoint;
};