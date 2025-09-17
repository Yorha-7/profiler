#pragma once
#include <chrono>
#include <iostream>
#include <sys/resource.h>

class Profiler {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    long startMemory;

    long getMemoryUsageKB();

public:
    Profiler();
    ~Profiler();
};
