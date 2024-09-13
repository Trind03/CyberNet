#pragma once
#include <asio.hpp>
#include "internet_computer.h"

class client : public ::internet_computer
{
public:
    client(client&) = delete;
    client();
    client(bool title,asio::ip::address_v4&& binding_addr,const unsigned int&& port);
    std::chrono::seconds timeout(std::chrono::seconds& time);

    void running(std::chrono::seconds moderator);
    int start();

    /* Getter funktions */

    asio::error_code get_Error();
    const unsigned int get_Port();
    asio::io_context get_Io_context();
    asio::ip::tcp::socket get_Sock();
    asio::ip::tcp::endpoint get_Endpoint();
    asio::ip::address_v4 get_Binding_addr();
    const bool get_Running_status();
    
protected:
    asio::error_code _Error;
    const unsigned int _Port;
    asio::io_context _Io_context;
    asio::ip::tcp::socket _Sock;
    asio::ip::tcp::endpoint _Endpoint;
    asio::ip::address_v4 _Binding_addr;
    bool _Running;
};