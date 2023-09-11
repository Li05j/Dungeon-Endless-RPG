#include <chrono>
#include <thread>

void wait(int sec) {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}