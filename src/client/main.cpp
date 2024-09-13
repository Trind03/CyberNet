#include <iostream>
#include <asio.hpp>
#include "client.h"
#include <memory>


int main()
{
    std::unique_ptr<client>(Client) = std::make_unique<client>(true,asio::ip::address_v4::from_string(client_connect), Active_Port);
    Client->start();
    return 0;
}