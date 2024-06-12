#include <asio.hpp>
#include "client.h"

Net_com::Net_com()
{}

Net_com::~Net_com()
{}

asio::ip::tcp::socket* Net_com::get_socket()
{
    return sock;
}