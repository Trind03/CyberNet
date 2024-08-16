#include <iostream>
#include <asio.hpp>
#include <functional>
#include <string>
#include "server.h"
#include "title.h"
#include "command.h"
#include "session.h"
static int debug_counter = 0;
#define checkpoint(message) std::cerr << message << std::endl;
#define _Debug_


server::server(unsigned short port,const char* filename): Port(std::move(port)), Io_context(), Endpoint(asio::ip::tcp::v4(),port), Acceptor(Io_context,Endpoint), Running(true),
Sock(Io_context)
{
    std::unique_ptr<std::thread>display_title = std::make_unique<std::thread>(title_server,std::move(filename));
    display_title->join();
};


void server::stop() { Running = false; }

bool server::get_running_status() const { return Running; }

const std::deque<session>& server::get_connections()
{ return this->Connections; }

void server::add_connection(asio::ip::tcp::socket &&Sock)
{
    checkpoint("9")
    session Session(std::move(Sock));
    checkpoint("10")
    //this->Connections.push_front(std::move(Session));
    checkpoint("11")
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
            if(!(it->calculate_time() < 10))
            {
                std::cout << "Disconnected from client: " << it->get_Address() << std::endl;
                this->disconnect_client(it);
            }

            else
                continue;
        }
    else
        return;
}

int server::broadcast_client(session *Session)
{
    //asio::write()
    return EXIT_SUCCESS;
}

int server::start(std::shared_ptr<command>Command)
{
#ifdef _Debug_
    std::unique_ptr<std::thread>command = std::make_unique<std::thread>(std::bind(&command::command_handler,*Command));
    try
    {
        checkpoint("1")
        this->Sock.open(asio::ip::tcp::v4(),this->Error);   
        checkpoint("2")
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
                this->session_status();

                Acceptor.listen();
                
                Acceptor.async_accept([this]( std::error_code Error,asio::ip::tcp::socket Sock)
                {
                    if(!Error)
                    {
                        checkpoint("3")
                        this->add_connection(std::move(Sock));
                        checkpoint("4")
                    }
                    
                    else
                    {
                        std::cerr << "Connection failure occurred" << std::endl;
                        checkpoint("5")
                    }
                });
                checkpoint("6")
                this->Io_context.run();
                checkpoint("7")

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