#include "internet_computer.h"
#include <chrono>

std::chrono::system_clock::time_point internet_computer::reset()
{
    return std::chrono::system_clock::now();
}

float internet_computer::calculate_time(std::chrono::system_clock *time_stamp)
{
    std::chrono::system_clock::time_point now_time = std::chrono::system_clock::now();
    std::chrono::duration<float>result = now_time - *(time_stamp);
    return result.count();
}