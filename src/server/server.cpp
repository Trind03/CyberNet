#include <iostream>
#include <asio.hpp>
#include <functional>
#include <string>
#include "server.h"
#include "title.h"
#include <thread>
#include "command.h"
#include "session.h"

// #define checkpoint(message) std::cerr << message << std::endl;

#define _Debug_


server::server(unsigned short port,bool title):
Port(std::move(port)),
Io_context(), 
Endpoint(asio::ip::tcp::v4(),
port),
Acceptor(Io_context,Endpoint),
Running(true),
Sock(Io_context)
{
    if(title)
    {
        const char* filename = "title.dat";
        title_server(std::move(filename));
    }
};


void server::stop()
{
    std::lock_guard<std::mutex>lock(resource_lock);
    Running = false;
}

bool server::get_running_status()
{
    std::lock_guard<std::mutex>lock(this->resource_lock);
    bool running = this->Running;
    return running;
}

const std::deque<session>& server::get_connections()
{ return this->Connections; }

void server::show_clients()
{
    int index = 1;

    std::cout << "**** Clients currently connected ****" << std::endl;
    for(std::deque<session>::iterator it = this->Connections.begin(); it != this->Connections.end(); it++)
    {
        std::cout << "Client - " << index++ << " - Address: " << it->get_Address() << " - Calculated time since last: " << it->calculate_time() <<  std::endl;
    }
}

void server::add_connection(asio::ip::tcp::socket &&Sock)
{
    session Session(std::move(Sock));

    std::lock_guard<std::mutex>lock(resource_lock);
    
    if(Session.is_valid())
        try
        {
            this->Connections.push_front(std::move(Session));
        }
        catch(const std::bad_alloc &ex)
        {
            std::cerr << "Unable to allocate more memory for new client" << '\n'; 
            std::cerr << "Shutting down..." << '\n'; 
            this->stop();
        }
        catch(const std::exception &ex)
        {
            std::cerr << "Unknown exception" << std::endl;
            this->stop();
        }
        
    else 
        std::cout << "Failed to add client to deque" << std::endl;
}


void server::disconnect_client(std::deque<session>::iterator it)
{
    std::lock_guard<std::mutex>lock(resource_lock);
    this->Connections.erase(it);
}

void server::session_status()
{
    while(this->Running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if(this->Connections.size() > 0)
            for(std::size_t i = 0; i < this->Connections.size(); i++)
            {
                if(!(this->Connections[i].calculate_time() < 10))
                {
                    std::cout << "Disconnected from client: " << this->Connections[i].get_Address() << std::endl;
                    this->Connections.erase(this->Connections.begin() + i);
                }

                else
                    continue;
            }
    }
}

int server::broadcast_client(session *Session,std::string m_data)
{
    if(!Session->is_valid())
        return EXIT_FAILURE;

    Session->Sock.set_option(asio::socket_base::broadcast(true));
    asio::const_buffer buffer(m_data.data(), m_data.size());

    asio::write(Session->Sock, buffer);
    return EXIT_SUCCESS;
}

int server::start(std::shared_ptr<command>Command)
{
#ifdef _Debug_
    std::unique_ptr<std::thread>command = std::make_unique<std::thread>(std::bind(&command::command_handler,*Command));
    try
    {
        this->Sock.open(asio::ip::tcp::v4(),this->Error);   
    }

    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        this->stop();
        command->join();
        return EXIT_FAILURE;
    }
    std::unique_ptr<std::thread>(session_tracker) = std::make_unique<std::thread>(std::thread(&server::session_status,this));
    this->running();
    command->join();
    session_tracker->join();
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
                Acceptor.listen();
                
                Acceptor.async_accept([this]( std::error_code Error,asio::ip::tcp::socket Sock)
                {
                    if(!Error)
                    {
                        this->add_connection(std::move(Sock));
                    }
                    
                    else
                    {
                        std::cerr << "Connection failure occurred" << std::endl;
                    }
                });
                this->Io_context.restart();
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