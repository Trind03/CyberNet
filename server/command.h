#pragma once
#include <string>
#include "session.h"
#include <vector>
#include "session.h"
#include <cstdlib>

struct command
{
    std::vector<user>*users;
    command(std::vector<user>*User): users(User) {}
    void command_handler();
    int list_connections();
};