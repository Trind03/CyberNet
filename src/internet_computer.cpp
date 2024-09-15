#include "internet_computer.h"
#include <chrono>
#include <iostream>

internet_computer::internet_computer() : auth_token("8423d8e6dea3f20d9adcd0b219d64c5fefd1002a940dd8b6781239203148761002489098b7201b905adae6c3036c8f4258d51fbed761dc60f5573ad58c156bb6")
{}

void internet_computer::reset(std::chrono::system_clock::time_point &time)
{
    time = std::chrono::system_clock::now();
}

float internet_computer::calculate_time(std::chrono::system_clock::time_point &time_stamp)
{
    std::chrono::system_clock::time_point now_time = std::chrono::system_clock::now();
    std::chrono::duration<float>result = now_time - time_stamp;
    return result.count();
}

    //std::cout << "Port: " << port << " - " << "Address: " << addr << std::endl; 