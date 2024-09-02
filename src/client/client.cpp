#include <asio.hpp>
#include <thread>
#include "title.h"
#include "client.h"

client::client(const char* filename,asio::ip::address&& binding_addr,const unsigned int&& port) : _Port(std::move(port)), _Binding_addr(std::move(binding_addr)),
_Io_context(), _Sock(asio::ip::tcp::socket(_Io_context)), _Endpoint(_Binding_addr, _Port), _Running(true)
{
    try
    {
        std::thread title_client = std::thread(std::bind(boot_message_client,filename));
        title_client.join();
    }
    catch(std::exception& E)
    {
        std::cout << E.what() << std::endl;
    }

}

