#include <memory>
#include <asio/include/asio.hpp>
#include "server.h"
#include "title.hpp"
#include "command.h"
#include <functional>


server::server(unsigned short port,const char* filename): Port(std::move(port)), Io_context(), Endpoint(asio::ip::tcp::v4(),port), Acceptor(Io_context,Endpoint), Sock(Io_context), Running(true),Connections(0)
{
    std::unique_ptr<std::thread>display_title = std::make_unique<std::thread>(title_server,std::move(filename));
    display_title->join();
};

void server::stop() { Running = false; }
bool server::get_running_status() const { return Running; }


int server::start(std::shared_ptr<command>Command)
{
    std::unique_ptr<std::thread>command = std::make_unique<std::thread>(std::bind(&command::command_handler,*Command));
    try
    {
        this->Sock.open(asio::ip::tcp::v4());
    }

    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        this->stop();
        command->join();
        exit(-1);
    }
    
    do 
    {
        this->Acceptor.listen();
        this->Acceptor.accept();
        
    } while(this->get_running_status());
    command->join();
    return 0;
}