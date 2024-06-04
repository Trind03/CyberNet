#include <memory>
#include <asio/include/asio.hpp>
#include "server.h"
#include "title.hpp"
#include "command.h"
#include <functional>
#include <future>
#include <string>
#define _Debug_

server::server(unsigned short port,const char* filename): Port(std::move(port)), Io_context(), Endpoint(asio::ip::tcp::v4(),port), Acceptor(Io_context,Endpoint), Running(true)
{
    std::unique_ptr<std::thread>display_title = std::make_unique<std::thread>(title_server,std::move(filename));
    display_title->join();
};

void server::stop() const { Running = false; }
bool server::get_running_status() const { return Running; }


int server::start(std::shared_ptr<command>Command)
{
    std::unique_ptr<std::thread>command = std::make_unique<std::thread>(std::bind(&command::command_handler,*Command));

    this->running();
    command->join();
    return 0;
}
void server::running()
{
    asio::ip::tcp::socket Sock(this->Io_context);
#ifdef _Debug_
    do
    {
        try
        {
            Acceptor.listen();
            asio::ip::tcp::socket socket(this->Io_context);
            Acceptor.accept(Sock);
            std::cout << "New connection" << std::endl;

            std::cout << "Client IP: " << Sock.remote_endpoint().address().to_string() << std::endl;
            std::cout << "Client Port: " << Sock.remote_endpoint().port() << std::endl;

        }
        
        catch (const std::exception& e)
        {
            std::cerr << this->Error.message() << '\n';
        }
    } while (this->get_running_status());
#endif

    #ifndef _Debug_
    do
    {
        this->Acceptor.listen();
        this->Acceptor.accept();
    } while(this->get_running_status());
    #endif
}