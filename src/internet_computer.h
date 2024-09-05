#pragma once
#include <chrono>


class internet_computer
{
protected:
    void virtual render_base() = 0;
    std::chrono::system_clock::time_point reset();
    float calculate_time(std::chrono::system_clock::time_point *time_stamp);
};