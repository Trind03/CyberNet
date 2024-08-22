#include <iostream>
#include <thread>
#include <asio.hpp>
#include "client.h"
#include <memory>

#define Checkpoint(message) std::cout << message << std::endl;
int main()
{
    std::unique_ptr<client>(Client) = std::make_unique<client>("title.dat",asio::ip::address::from_string("127.0.0.1"), 5554);

    Client->_Sock.connect(Client->_Endpoint,Client->_Error);

    if(!Client->_Error)
    {
        std::cout << std::endl << "Connected to server" << std::endl;
        while(Client->_Running)
        {

        }
    }

    else
    {
        std::cerr << "Connection failure " << Client->_Error.message() << std::endl;
    }
    return 0;
}