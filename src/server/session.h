#pragma once
#include <asio.hpp>
#include <chrono>
#include <vector>

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
    std::chrono::system_clock::time_point& get_time();
    std::string get_Address();
    int broadcast_client(std::string m_data);
    void response();

    std::chrono::system_clock::time_point _Time_stamp;
    asio::ip::tcp::socket _Sock;
    std::vector<unsigned char>_Buffer;
    asio::error_code _Error;
};