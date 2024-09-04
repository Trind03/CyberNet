#include <iostream>
#include <asio.hpp>
#include "client.h"
#include <memory>

#define IP "10.4.4.57"
#define Port 5554


int main()
{
    std::unique_ptr<client>(Client) = std::make_unique<client>(true,asio::ip::address::from_string(IP), Port);
    Client->start();
    return 0;
}