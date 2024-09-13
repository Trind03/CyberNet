#pragma once
#include "client.h"
#include "internet_computer.h"

class client_t : public client
{
public:
    client_t(bool title,asio::ip::address_v4&& binding_addr,const unsigned int&& port);
};