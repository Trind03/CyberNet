#include <iostream>
#include <string>
#include <memory>
#include "command.h"

void command::command_handler()
{
    std::string value;
    while(true)
    {
        std::cout << "> ";
        std::getline(std::cin,value);
    }
}