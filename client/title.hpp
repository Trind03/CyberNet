#include <iostream>
#include <functional>
#include <memory>
#include <fstream>
#include <string>

std::function<void(const char*)>boot_message_client = [=](const char* filename)
{
    std::unique_ptr<std::fstream>(stream) = std::make_unique<std::fstream>(filename);
    //stream->open(filename);

    if(stream->is_open())
    {
        std::string line;
        while(std::getline((*stream),line))
        {

        }
    }
};