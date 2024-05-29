#include <vector>
#include <memory>
#include <thread>
#include <asio/include/asio.hpp>
#include "server.h"
#include "title.hpp"

server::server(unsigned short&& port, std::string&& filename) : Port(port), Io_context(), Endpoint(asio::ip::tcp::v4(),port),Acceptor(Io_context,Endpoint), Sock(Io_context)
{
    std::unique_ptr<std::thread>display_title = std::make_unique<std::thread>(title_server,filename);

    display_title->join();
};