#include <iostream>
#include <chrono>

// A class for counting time
class StopWatch {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

public:
    StopWatch(void) :
    start { std::chrono::high_resolution_clock::now() } { }

    // Returns the difference between the current moment in time and the initial time point
    int64_t lap(void) const {
        return std::chrono::nanoseconds(std::chrono::high_resolution_clock::now() - start).count();
    }

    // Reset the initial time point
    void reset(void) {
        start = std::chrono::high_resolution_clock::now();
    }

    // The combination of lap() and reset() [returns nanoseconds]
    int64_t mark(void) {
        int64_t r = lap();
        reset();
        return r;
    }

    // Same as mark() but in seconds
    double mark_s(void) {
        return (double) mark() / 1'000'000'000;
    }
};