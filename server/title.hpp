#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <memory>

std::function<void(const char*&&)> title_server = [&](const char*&& filename)
{
    std::unique_ptr<std::fstream>(stream) = std::make_unique<std::fstream>(filename);
    //stream->open(filename);

    if(stream->is_open())
    {
        std::string line;
        while(std::getline((*stream),line))
        {
            std::cout << line << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
    else
    {
        std::cout << "Error title file not found" << std::endl;
        exit(-1);
    }
};
