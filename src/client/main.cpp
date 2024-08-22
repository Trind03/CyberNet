#include <iostream>
#include <thread>
#include <asio.hpp>
#include "client.h"
static bool running = true;

int main()
{
    client client("title.dat",asio::ip::address::from_string("127.0.0.1"), 5554);

    client._Sock.connect(client._Endpoint);

    if(!client._Error)
    {
        std::cout << std::endl << "Connected to server" << std::endl;
        while(running)
        {

        }
    }

    else
    {
        std::cerr << "Connection failure " << client._Error.message() << std::endl;
    }
    return 0;
}