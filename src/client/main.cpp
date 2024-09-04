#include <iostream>
#include <asio.hpp>
#include "client.h"
#include <memory>

int main()
{
    std::unique_ptr<client>(Client) = std::make_unique<client>(true,asio::ip::address::from_string("127.0.0.1"), 5554);
    Client->start();
    return 0;
}