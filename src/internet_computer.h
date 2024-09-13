#pragma once
#include <chrono>
#include <string>

class internet_computer
{
protected:
    internet_computer(){}
    void reset(std::chrono::system_clock::time_point &time);
    float calculate_time(std::chrono::system_clock::time_point &time_stamp);
};