#include <string>
#include <iostream>
#include "command.h"
#include "utils.hpp"
#include <asio/include/asio.hpp>
#include <cstdlib>


void command::command_handler()
{
    std::string Command;

    while(true)
    {
        std::cout << "> "; getline(std::cin, Command);

        if(Command == "" || Command == " ")
            std::cout << std::endl;

        else if(Command == "clear" || Command == "Clear")
        {
            for(int i = 0; i < 40; i++)
                std::cout << "\n\n";
        }

        else if(Command == "" || Command == " ")
            std::cout << std::endl;

        else if(Command == "exit" || Command == "Exit")
        {
            std::cout << "K bye " << std::endl;
            exit(0);
        }

        else
            std::cout << "Invalid command" << std::endl;
    }
}
