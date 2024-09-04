#include <asio.hpp>
#include <chrono>
#include <iostream>
#include "session.h"
#include <mutex>

void session::reset()
{
    time_stamp = std::chrono::system_clock::now();
}

float session::calculate_time()
{
    std::chrono::system_clock::time_point now_time = std::chrono::system_clock::now();
    std::chrono::duration<float>result = now_time - time_stamp;
    return result.count();
}


bool session::is_valid()
{
    return Sock.is_open();
}

std::string session::get_Address()
{
    return Sock.remote_endpoint().address().to_string();
}

session::session(session&& other): Sock(std::move(other.Sock)), time_stamp(other.time_stamp)
{
    std::cout << "Session saved to memory" << std::endl;
}

session::session(asio::ip::tcp::socket &&socket): Sock(std::move(socket))
{
    time_stamp = std::chrono::system_clock::now();
    std::cout << "Connected to: " << Sock.remote_endpoint().address().to_string() << std::endl;
}

int session::broadcast_client(std::string m_data)
{
    if(!is_valid()) return EXIT_FAILURE;

    Sock.set_option(asio::socket_base::broadcast(true));
    asio::const_buffer buffer(m_data.data(), m_data.size());

    asio::write(Sock, buffer);
    return EXIT_SUCCESS;
}

session::~session()
{
    
}