#include <asio.hpp>
#include "client.h"
#include <chrono>

client::client()
{
    
}

client::~client()
{}

void client::reset_timer()
{
    std::chrono::seconds duration(0);
}

std::chrono::steady_clock client::get_last_ping() const
{
    return last_response;
}

asio::ip::tcp::endpoint client::get_endpoint() const
{
    return Endpoint;
}