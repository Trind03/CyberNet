#pragma once
#include <asio.hpp>
#include <chrono>

class session
{
public:
    session(const session&)noexcept = delete;
    session& operator=(const session&) = delete;

    session(asio::ip::tcp::socket &&Socket);
    session& operator=(session&&)noexcept = default;
    
    session(session&& other);
    ~session();
    
    bool is_valid();
    float calculate_time();
    void reset();
    std::string get_Address();

    std::chrono::system_clock::time_point time_stamp;
    asio::ip::tcp::socket Sock;
};