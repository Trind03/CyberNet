#include <asio.hpp>
#include <memory>
#include "server.h"
#include "command.h"

#define  ASIO_STANDALONE 1

int main(int argc,const char** argv)
{
    std::shared_ptr<server>Server = std::make_shared<server>(Active_Port,"title.dat");
    std::shared_ptr<command>Command = std::make_shared<command>(Server);
    Server->start(Command);
    return EXIT_SUCCESS;
}