#include <iostream>
#include <cstring>
#include <asio/include/asio.hpp>


int main(int argc, char *argv[])
{
    if(strcmp(argv[1],"server") == 0 || strcmp(argv[1],"Server"))
        std::cout << "server";

    else if(strcmp(argv[1],"client") == 0 || strcmp(argv[1],"Client"))
        std::cout << "client";

    else
        std::cout << "Invalid arg";
    
    return 0;
}