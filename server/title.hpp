#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <memory>

template <typename T>
std::function<void(T)> title_server = [](T filename)
{
    std::unique_ptr<std::fstream>(stream) = std::make_unique<std::fstream>(filename);

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
