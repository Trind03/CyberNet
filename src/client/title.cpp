#include <iostream>
#include <functional>
#include <memory>
#include <fstream>
#include <string>
#include "title.h"

int boot_message_client(const char*&  filename)
{
    std::unique_ptr<std::fstream>(stream) = std::make_unique<std::fstream>(filename);

    if(stream->is_open())
    {
        std::string line;
        while(std::getline((*stream),line))
        {
            std::cout << line << std::endl;
        }
    }

    else
    {
        std::cerr << "Error title file not found" << std::endl;
        exit(-1);
    }
    return EXIT_SUCCESS;
};