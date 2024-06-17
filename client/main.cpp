#include <iostream>
#include <thread>
#include <asio.hpp>
#include "title.h"
#include "title.h"

static bool running = true;

int main()
{
    const char* filename = "title.dat";
    std::thread title_client = std::thread(std::bind(boot_message_client,filename));

    asio::ip::address IPV4 = asio::ip::address::from_string("127.0.0.1");
    constexpr int target_port = 5554;  
    
    asio::error_code error;
    asio::io_context io_context;
    asio::ip::tcp::endpoint endpoint(IPV4,target_port);
    asio::ip::tcp::socket sock(io_context);
    title_client.join();

    sock.connect(endpoint,error);

    if(!error)
    {
        std::cout << std::endl << "Connected to server" << std::endl;
        while(running)
        {
            
        }
    }

    else
    {
        std::cerr << "Connection failure " << error.message() << std::endl;
    }
    return 0;
}