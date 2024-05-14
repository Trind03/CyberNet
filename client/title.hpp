#include <iostream>
#include <functional>
#include <memory>
#include <fstream>


std::function<void(const char*)>boot_message_client = [=](const char* filename)
{
    std::unique_ptr<std::fstream>(stream) = std::make_unique<std::fstream>(filename);

    
};