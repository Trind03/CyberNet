#pragma once
#include <asio.hpp>
#include <chrono>

class session
{
public:
    session(asio::ip::tcp::socket *Socket);
    ~session();
    float calculate_time();
    void reset();
    std::string getinfo()
    {
        return Sock.local_endpoint().address().to_string();
    }
private:
    std::chrono::system_clock::time_point time_stamp;
    asio::ip::tcp::socket *Sock;
};