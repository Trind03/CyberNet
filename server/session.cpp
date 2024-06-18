#include <asio.hpp>
#include <chrono>
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
    return 0.0;
}


session::session(asio::ip::tcp::endpoint endpoint): Endpoint(endpoint)
{
    reset();
}