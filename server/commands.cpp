#include <string>
#include <iostream>
#include "command.h"
#include "utils.hpp"


command::command(session_details *Session): session(Session) {}

void command::command_handler()
{
    std::string Command;

    while(true)
    {
        std::cout << "> "; getline(std::cin, Command);

        if(Command == "clear" || Command == "Clear")
            for(int i = 0; i < 20; i++)
                std::cout << std::endl;

        else if(Command == "list" || Command == "List")
            list_connections();
    }
}


int command::list_connections()
{
    if(session->curr_connections <= 0)
    {
        std::cout << "No active connections" << std::endl;
        return 0;
    }
    
    else
    {
        for(int i = 0; i < session->User.size(); i++)
            std::cout << session->User[i].ID << " - " << session->User[i].IPV4 << std::endl;
            return 0;
    }
    return -1;
}