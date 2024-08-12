#include <asio.hpp>
#include <chrono>
#include <iostream>
#include "session.h"


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


session::session(asio::ip::tcp::socket &&socket): Sock(static_cast<asio::ip::tcp::socket&&>(socket))
{
    time_stamp = std::chrono::system_clock::now();
}

session::~session()
{
    std::cout << "Client " << Sock.remote_endpoint().address().to_string() << " disconnected" << std::endl;
}