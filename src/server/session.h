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
    std::chrono::system_clock::time_point* get_time();
    std::string get_Address();
    int broadcast_client(std::string m_data);

    std::chrono::system_clock::time_point time_stamp;
    asio::ip::tcp::socket Sock;
};