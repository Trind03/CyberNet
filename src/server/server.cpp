#include <iostream>
#include <memory>
#include <asio.hpp>
#include <functional>
#include <string>
#include "server.h"
#include "title.h"
#include "command.h"
#include "session.h"

#define _Debug_


server::server(unsigned short port,const char* filename): Port(std::move(port)), Io_context(), Endpoint(asio::ip::tcp::v4(),port), Acceptor(Io_context,Endpoint), Running(true)
{
    std::unique_ptr<std::thread>display_title = std::make_unique<std::thread>(title_server,std::move(filename));
    display_title->join();
};


void server::stop() { Running = false; }

bool server::get_running_status() const { return Running; }

std::deque<session> server::get_connections()const { return this->Connections; }

void server::add_connection(asio::ip::tcp::endpoint &&Endpoint)
{
    session Session(std::move(Endpoint));
    this->Connections.push_front(Session);
}


void server::disconnect_client(std::deque<session>::iterator it)
{
    this->Connections.erase(it);
}

void server::session_status()
{
    if(this->Connections.size() > 0)
        for(std::deque<session>::iterator it = this->Connections.begin(); it < this->Connections.end(); ++it)
        {
            if(!it->calculate_time() < 10)
                this->disconnect_client(it);

            else
                continue;
        }
    else
        return;
}

int server::broadcast_client(session *Session)
{
    return EXIT_SUCCESS;
}

int server::start(std::shared_ptr<command>Command)
{
#ifdef _Debug_
    this->Sock = std::make_unique<asio::ip::tcp::socket>(Io_context);
    std::unique_ptr<std::thread>command = std::make_unique<std::thread>(std::bind(&command::command_handler,*Command));
    try
    {
        this->Sock->open(asio::ip::tcp::v4(),this->Error);

    }

    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        this->stop();
        command->join();
        return EXIT_FAILURE;
    }
    this->running();
    command->join();
    return 0;

#else

    this->Sock = std::make_unique<asio::ip::tcp::socket>(Io_context);
    std::unique_ptr<std::thread>command = std::make_unique<std::thread>(std::bind(&command::command_handler,*Command));
  
    this->running();
    command->join();
    return 0;

#endif
}

void server::running()
{
#ifdef _Debug_
        do
        {
            try
            {
                asio::ip::tcp::socket sock(this->Io_context);
                Acceptor.listen();
                
                Acceptor.async_accept([this](const std::error_code& Error,const asio::ip::tcp::socket& Sock)
                {
                    if(!Error)
                    {
                        this->add_connection(Sock.remote_endpoint());
                        //std::cout << this->get_connections().size() << " Connection " << Sock.remote_endpoint().address() << " on port " << Sock.remote_endpoint().port() << std::endl;
                    }
                    
                    else
                    {
                        std::cerr << "Connection failure occurred" << std::endl;
                    }
                });
                this->Io_context.run();
            }
            
                
                catch (const std::exception& e)
                {
                    std::cerr << "Caught exception " << e.what() << std::endl;;
                    std::cerr << this->Error.message() << '\n';
                }
        } while (this->get_running_status());
    
#else
    do
    {
        this->Acceptor.listen();
        this->Acceptor.accept();
    } while(this->get_running_status());
#endif
}