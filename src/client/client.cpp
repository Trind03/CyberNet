#include <asio.hpp>
#include <iostream>
#include <thread>
#include "title.h"
#include "client.h"
#include <chrono>


client::client(bool title,asio::ip::address_v4&& binding_addr,const unsigned int&& port) : _Port(std::move(port)), _Binding_addr(std::move(binding_addr)),
_Io_context(), _Sock(asio::ip::tcp::socket(_Io_context)), _Endpoint(_Binding_addr, _Port), _Running(true)
{
    const char* filename = "title.dat";
    if(title)
    {
        std::thread title_client = std::thread(std::bind(boot_message_client,filename));
        title_client.join();
    }

}



std::chrono::seconds client::timeout(std::chrono::seconds* ptr)
{
    std::this_thread::sleep_for(*ptr);
    return std::chrono::seconds(5);
}

void client::start()
{
    std::chrono::seconds *time = new std::chrono::seconds(5);
    while(_Error)
    {
        _Sock.connect(_Endpoint,_Error);

        if(!_Error)
        {
            std::cout << std::endl << "Connected to server" << std::endl;
            delete time;
        }

        else
        {
            std::cerr << "Connection failure " << _Error.message() << std::endl;
            *(time) += timeout(time);
        }
    }
}
