#include <vector>
#include <memory>
#include <thread>
#include <asio/include/asio.hpp>
#include "server.h"
#include "title.hpp"

server::server(unsigned short port,const char* filename): Port(std::move(port)), Io_context(), Endpoint(asio::ip::tcp::v4(),port), Acceptor(Io_context,Endpoint), Sock(Io_context), Running(true)
{
    std::unique_ptr<std::thread>display_title = std::make_unique<std::thread>(title_server,std::move(filename));
    display_title->join();
};
void server::stop() { Running = false; }
bool server::get_running_status() { return Running; }

int server::start(std::shared_ptr<server>Server)
{
    try
    {
        Server->Sock.open(asio::ip::tcp::v4());
    }

    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    do 
    {
        Server->Acceptor.listen();
        Server->Acceptor.accept();

    } while(Server->get_running_status());
    return 0;
}