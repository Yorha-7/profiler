#include "profiler.hpp"

long Profiler::getMemoryUsageKB() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;  // in KB
}

Profiler::Profiler() {
    start = std::chrono::high_resolution_clock::now();
    startMemory = getMemoryUsageKB();
}

Profiler::~Profiler() {
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    long endMemory = getMemoryUsageKB();
    long usedMemory = endMemory - startMemory;

    std::cout << "\n[Profiler] Execution Time: "
              << duration.count() << " ms\n";
    std::cout << "[Profiler] Memory Usage: "
              << usedMemory << " KB\n";
}
