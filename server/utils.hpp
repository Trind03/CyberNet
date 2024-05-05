#pragma once
#include <iostream>
#include <asio/include/asio.hpp>
#include <thread>

static bool running = true;

static void Mov_Cursor(int row, int col)
{
	std::cout << "\033[" << row << ";" << col << "H";
}

static void Connection_Handler(asio::ip::tcp::acceptor &acceptor, asio::ip::tcp::socket &socket)
{
    try
    {
        while(running)
        {
            acceptor.accept(socket);
            asio::ip::tcp::endpoint conn = socket.remote_endpoint();
            std::cout << "Connection established -> " << conn.address() << ":" << conn.port() << std::endl;
            socket.close();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
} 
