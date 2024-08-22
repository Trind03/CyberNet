#include <asio.hpp>
#include "client.h"

client::client(asio::ip::address&& binding_addr,uint8_t&& port) : _Port(std::move(port)), _Binding_addr(std::move(binding_addr)),
_Io_context(), _Sock(asio::ip::tcp::socket(_Io_context))
{

}

