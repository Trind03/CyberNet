#include <asio.hpp>
#include <chrono>
#include <iostream>
#include "session.h"
#include <mutex>

std::chrono::system_clock::time_point& session::get_time()
{
    return _Time_stamp;
}

bool session::is_valid()
{
    return _Sock.is_open();
}

std::string session::get_Address()
{
    return this->_Sock.remote_endpoint().address().to_string();
}

session::session(session&& other): _Sock(std::move(other._Sock)), _Time_stamp(other._Time_stamp), _Buffer(std::vector<unsigned char>(1240))
{
    std::cout << "Session saved to memory" << std::endl;
}

session::session(asio::ip::tcp::socket &&socket): _Sock(std::move(socket)), _Buffer(std::vector<unsigned char>(1240))
{
    this->_Time_stamp = std::chrono::system_clock::now();
    std::cout << "Connected to: " << this->_Sock.remote_endpoint().address().to_string() << std::endl;
}

int session::broadcast_client(std::string m_data)
{
    if(!is_valid()) return EXIT_FAILURE;

    this->_Sock.set_option(asio::socket_base::broadcast(true));
    asio::const_buffer buffer(m_data.data(), m_data.size());

    asio::write(this->_Sock, buffer);
    return EXIT_SUCCESS;
}

void session::response()
{
    if(this->_Sock.available(this->_Error) > 0 && !this->_Error)
    {
        std::size_t bytes = this->_Sock.read_some(asio::buffer(this->_Buffer));
        for(uint16_t i = 0; i < bytes; i++)
        {
            std::cout << this->_Buffer[i] << std::endl;
        }
    }
}

session::~session()
{
    
}