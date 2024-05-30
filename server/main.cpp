#pragma once
#include <asio/include/asio.hpp>
#include <memory>
#include "utils.hpp"
#include "command.h"
#include "server.h"

int main()
{
    std::unique_ptr<server>Server = std::make_unique<server>(5554,"title.dat");
    Server->start(Server);
    return EXIT_SUCCESS;
}