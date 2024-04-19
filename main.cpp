#include <iostream>
#include <cstring>
#include "server.hpp"
#include "client.hpp"
int main(int argc, char *argv[])
{
    if(strcmp(argv[1],"server") == 0 || strcmp(argv[1],"Server"))
        return server();

    else if(strcmp(argv[1],"client") == 0 || strcmp(argv[1],"Client"))
        return client();

    else
        std::cout << "Invalid arg";
    
    return 0;
}