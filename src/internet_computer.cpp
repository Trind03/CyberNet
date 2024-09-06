#include "internet_computer.h"
#include <chrono>

void internet_computer::reset(std::chrono::system_clock::time_point *time)
{
    *time = std::chrono::system_clock::now();
}

float internet_computer::calculate_time(std::chrono::system_clock::time_point *time_stamp)
{
    std::chrono::system_clock::time_point now_time = std::chrono::system_clock::now();
    std::chrono::duration<float>result = now_time - *(time_stamp);
    return result.count();
}