#include <asio.hpp>
#include "client.h"

client::client()
{}

client::~client()
{}

asio::ip::tcp::socket* client::get_socket()
{
    return sock;
}