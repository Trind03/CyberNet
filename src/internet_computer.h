#pragma once
#include <chrono>


class internet_computer
{
protected:
    virtual void render() = 0;
    void reset(std::chrono::system_clock::time_point* time);
    float calculate_time(std::chrono::system_clock::time_point *time_stamp);
};