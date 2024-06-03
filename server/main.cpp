#pragma once
#include <asio/include/asio.hpp>
#include <memory>
#include "server.h"
#include "command.h"

int main(int argc,const char[])
{
    std::shared_ptr<server>Server = std::make_shared<server>(5554,"title.dat");
    std::shared_ptr<command>(Command) = std::make_shared<command>(Server);
    Server->start(Server,Command);
    return EXIT_SUCCESS;
}