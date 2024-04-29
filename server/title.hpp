#pragma once
#include <iostream>
#include <fstream>
#include <functional>

std::function<void()> boot_message = []()
{
    std::cout << "\t\t\t" << "***** Prototype Of CyberNet Software *****" << "\n\n\n";
};
