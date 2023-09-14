#include "helperUtils.h"

#include "./src/utils/debugUtils.h"

#include <chrono>
#include <cstdlib>
#include <random>
#include <thread>

void clearScreen() {
#ifdef _WIN32
    // Use "cls" to clear the screen on Windows
    system("cls");
#else
    // Use "clear" to clear the screen on Unix-like systems
    system("clear");
#endif
}

// generated number > lo but < hi
int generateRandomNumber(int lo, int hi) {
    // Seed the random number generator with a random device
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the range for your random number
    std::uniform_int_distribution<int> distribution(lo, hi);

    // Generate a random number
    int ret = distribution(gen);

    return ret;
}

void wait(int sec) {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}