#include <string>
#include "command.h"
#include <iostream>
#include "utils.hpp"

command::command(session_details *session): Session(session)
{}

void command::command_handler()
{
    std::string Command;

    std::cout << "> "; getline(std::cin, Command);

    if(Command == "clear" || Command == "Clear")
        for(int i = 0; i < 20; i++)
            std::cout << std::endl;

    else if(Command == "list" || Command == "List")
        list_connections();
}

void command::list_connections()const
{
    if(Session->curr_connections <= 0)
    {
        std::cout << "No active connections" << std::endl;
    }
    
    else
    {
        for(int i = 0; i < Session->User.size(); i++)
            std::cout << Session->User[i].ID << " - " << Session->User[i].IPV4 << std::endl;
    }
}