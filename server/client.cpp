#include <asio.hpp>
#include <chrono>
#include "client.h"

void client::reset()
{
    time_stamp = std::chrono::system_clock::now();
}

float client::calculate_time()
{
    std::chrono::system_clock::time_point now_time = std::chrono::system_clock::now();
    std::chrono::duration<float>result = now_time - time_stamp;
    return result.count();
}

client::client(asio::ip::tcp::endpoint endpoint): Endpoint(endpoint)
{
    reset();
}
