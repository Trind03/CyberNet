#include <asio.hpp>
#include "client_t.h"

client_t::client_t(bool title,asio::ip::address_v4&& binding_addr,const unsigned int&& port) : client(title,std::move(binding_addr),std::move(port))
{}
