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
    std::cout << "Port: " << port << " - " << "Address: " << binding_addr << std::endl; 
}


asio::error_code client::get_Error()
{
    return _Error;
}
const unsigned int client::get_Port()
{
    return _Port;
}

asio::ip::tcp::endpoint client::get_Endpoint()
{
    return _Endpoint;
}
asio::ip::address_v4 client::get_Binding_addr()
{
    return _Binding_addr;
}
const bool client::get_Running_status()
{
    return _Running;
}


std::chrono::seconds client::timeout(std::chrono::seconds& time)
{
    std::this_thread::sleep_for(time);
    return std::chrono::seconds(5);
}

int client::start()
{
    bool running_timeout = true;
    std::chrono::seconds time = std::chrono::seconds(5);
    while(running_timeout)
    {
        _Sock.close();
        _Sock.open(_Endpoint.protocol());
        _Sock.connect(_Endpoint,_Error);

        if(!_Error)
        {
            std::cout << std::endl << "Connected to server" << std::endl;
            running_timeout = !running_timeout;
            return EXIT_SUCCESS;
        }

        else if(time.count() >= 60)
        {
            std::cout << "Connection failure terminating program.." << std::endl;
            return EXIT_FAILURE;
        }

        else
        {
            std::cerr << "Connection failure: " << _Error.message() << " awaiting " << time.count() << " seconds" << std::endl;
            time += timeout(time);
        }
    }
    return EXIT_SUCCESS;
}

void client::running(std::chrono::seconds moderator)
{

    while (_Running)
    {
        std::this_thread::sleep_for(moderator);
    }
    
}