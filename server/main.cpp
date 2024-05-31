#pragma once
#include <asio/include/asio.hpp>
#include <memory>
#include "server.h"

int main(int argc,const char[])
{
    std::shared_ptr<server>Server = std::make_shared<server>(5554,"title.dat");
    Server->start(Server);
    return EXIT_SUCCESS;
}