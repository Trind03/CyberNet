#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include "server.h"
class command
{
public:
    command(std::shared_ptr<server>(ptr));
    void command_handler();
private:
    std::shared_ptr<server>(Server);
};