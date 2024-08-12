#pragma once
#include <asio.hpp>
#include <chrono>

class session
{
public:
    session(asio::ip::tcp::socket &&Socket);
    session(const session&)noexcept = default;
    session& operator=(session&&)noexcept = default;
    ~session();
    float calculate_time();
    void reset();
    std::string get_Address()
    {
        return Sock.remote_endpoint().address().to_string();
    }
private:
    std::chrono::system_clock::time_point time_stamp;
    asio::ip::tcp::socket Sock;
};