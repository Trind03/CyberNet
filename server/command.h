#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include "user.h"
struct command
{
    std::vector<user>*users;
    command(std::vector<user>*User): users(User) {}
    void command_handler();
    int list_connections();
};