#pragma once

#include <chrono>

class Timer
{
public:
    Timer()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }

    void reset()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const
    {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        return duration.count() * 0.001;
    }

    double elapsed_seconds() const
    {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
        return duration.count();
    }

private:
    std::chrono::high_resolution_clock::time_point start_time;
};