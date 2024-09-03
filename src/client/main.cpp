#include <iostream>
#include <asio.hpp>
#include "client.h"
#include <memory>

int main()
{
    std::unique_ptr<client>(Client) = std::make_unique<client>(true,asio::ip::address::from_string("127.0.0.1"), 5554);

    Client->_Sock.connect(Client->_Endpoint,Client->_Error);

    if(!Client->_Error)
    {
        std::cout << std::endl << "Connected to server" << std::endl;
        while(Client->_Running)
        {}
    }

    else
    {
        std::cerr << "Connection failure " << Client->_Error.message() << std::endl;
    }
    return 0;
}