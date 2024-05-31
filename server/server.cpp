#include <vector>
#include <memory>
#include <thread>
#include <asio/include/asio.hpp>
#include "server.h"
#include "title.hpp"
#include "command.h"

server::server(unsigned short port,const char* filename): Port(std::move(port)), Io_context(), Endpoint(asio::ip::tcp::v4(),port), Acceptor(Io_context,Endpoint), Sock(Io_context), Running(true)
{
    std::unique_ptr<std::thread>display_title = std::make_unique<std::thread>(title_server,std::move(filename));
    display_title->join();
};
void server::stop() { Running = false; }
bool server::get_running_status() { return Running; }

int server::start(std::shared_ptr<server>Server)
{
    std::unique_ptr<std::thread>command = std::make_unique<std::thread>(command::command_handler);
    try
    {
        Server->Sock.open(asio::ip::tcp::v4());
    }

    catch(std::exception* ex)
    {
        std::cout << ex->what() << std::endl;
        command->join();
        return -1;
    }
    
    do 
    {
        Server->Acceptor.listen();
        Server->Acceptor.accept();

    } while(Server->get_running_status());
    command->join();
    return 0;
}