#include <string>
#include <iostream>
#include "command.h"
#include "utils.hpp"
#include <asio/include/asio.hpp>
#include <cstdlib>
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

        else if(Command == "exit" || Command == "Exit")
        {
            std::cout << "K bye " << std::endl;
            exit(0);
        }

        else
            std::cout << "Invalid command" << std::endl;
    }
}

std::ostream& operator <<(std::ostream& stream,std::vector<user>&arr)
{
    for(int i = 0; i < arr.size(); i++)
        stream << std::endl << arr[i].ID << " - " << arr[i].IPV4.address() << std::endl;
    return stream;
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
        std::cout << session->User;
        return 0;
    }
    return -1;
}