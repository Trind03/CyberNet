#pragma once
#include <chrono>


class internet_computer
{
    std::chrono::system_clock::time_point reset();
    float calculate_time(std::chrono::system_clock *time_stamp);
};