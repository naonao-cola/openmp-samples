#pragma once

// steady_clock example
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;

class SteadyClock
{
public:
    void Init();
    void Release();

    void Test();
    void Test_high_resolution();

    void Start();
    void End();
    void Duration(std::string TimeInfo);

    void Start_high();
    void End_high();
    void Duration_high(std::string TimeInfo);

private:

    steady_clock::time_point time_start;
    steady_clock::time_point time_end;
    duration<double> time_duration;

    high_resolution_clock::time_point time_start_H;
    high_resolution_clock::time_point time_end_H;
    duration<double> time_duration_H;
};
