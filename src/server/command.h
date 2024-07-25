#pragma once
#include <string>
#include <memory>
#include <array>

class server;

class command
{
public:
    command(std::shared_ptr<server>_Server);
    void command_handler();
private:
    std::shared_ptr<server>Server;

    std::array<const char*,3> commands = {"clear"," ","exit"};
};