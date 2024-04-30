#include <string>
#include <iostream>
#include "command.h"
#include "utils.hpp"
#include <asio/include/asio.hpp>
#include <cstdlib>
#include "user.h"

//command::command(std::vector<user>*User): users(User) {}


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

        else if(Command == "list" || Command == "List")
            list_connections();

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
/*
std::ostream& operator <<(std::ostream& stream,std::vector<user>*array)
{
    for (const auto& arr: *array) {
        stream << std::endl << arr.ID << " - " << arr.IPV4.address() << std::endl;
    }
    return stream;
}
*/
int command::list_connections()
{
    
    if(users->size() <= 0)
    {
        std::cout << "No active connections" << std::endl;
        return 0;
    }
    
    else
    {
        //std::cout << &users;
        return 0;
    }
    return -1;
}