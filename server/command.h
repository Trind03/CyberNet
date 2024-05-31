#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include "server.h"
class command
{
public:
    static void command_handler(std::shared_ptr<server>Server);
};