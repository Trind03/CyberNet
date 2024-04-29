#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <string>

std::function<void(const char*)> boot_message = [=](const char* filename)
{
    std::fstream stream;
    stream.open(filename);

    if(stream.is_open())
    {
        std::string line;
        while(std::getline(stream,line))
        {
            std::cout << line << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to find title file" << std::endl;
    }
};
