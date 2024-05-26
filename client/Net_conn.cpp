#include <asio/include/asio.hpp>
#include "Net_com.h"

Net_com::Net_com()
{}

Net_com::~Net_com()
{}

asio::ip::tcp::socket* Net_com::get_socket()
{
    return sock;
}