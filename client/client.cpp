#include <asio.hpp>
#include "client.h"

client::client()
{}

client::~client()
{}

void client::reset_timer()
{
    last_response = std::chrono::
}

std::chrono::seconds client::get_last_ping() const
{
    return (*last_response);
}

asio::ip::tcp::endpoint* client::get_endpoint() const
{
    return Endpoint;
}