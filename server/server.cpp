#include <vector>
#include <memory>
#include <thread>
#include <asio/include/asio.hpp>
#include "server.h"
#include "title.hpp"

server::server(unsigned short&& port, const char*&& filename) : Port(port), Io_context(), Endpoint(asio::ip::tcp::v4(),port), Acceptor(Io_context,Endpoint), Sock(Io_context)
{
    std::unique_ptr<std::thread>display_title = std::make_unique<std::thread>(title_server,filename); display_title->join();
};

bool server::get_running_status() {return running;}

void server::start(server* Server)
{


}