#pragma once
#include <asio/include/asio.hpp>
#include <thread>
#include "utils.hpp"
#include "command.h"
#include "user.h"
#include "server.h"

int main()
{
    server server(5554,"title.dat");
    return EXIT_SUCCESS;
}