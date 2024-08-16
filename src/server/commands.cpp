#include <string>
#include <iostream>
#include <asio.hpp>
#include <cctype>
#include "command.h"
#include "server.h"

command::command(std::shared_ptr<server>_Server): Server(_Server)
{}

void command::command_handler()
{
    std::string Command;

    while(Server->get_running_status())
    {        
        std::cout << "> "; getline(std::cin, Command);

        if(Command == "" || Command == " ")
            std::cout << std::endl;

        else if(Command == this->commands[0])
        {
            for(int i = 0; i < 20; i++)
                std::cout << std::endl;
        }

        else if(Command == this->commands[2])
        {
            std::cout << "K bye " << std::endl;
            exit(0);
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
}
