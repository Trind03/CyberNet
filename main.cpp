#include <iostream>
#include <cstring>
#include "client.hpp"
#include "server.hpp"

#ifdef _WIN32
#define _WIN32_WINNT 0x0601
#endif

int main(int argc, char *argv[])
{
    
    if(strcmp(argv[1],"server") == 0 || strcmp(argv[1],"Server"))
        return server();

    if(strcmp(argv[1]," client") == 0 || strcmp(argv[1]," Client"))
        return client();

    else
        std::cout << "Invalid arg";
    
}