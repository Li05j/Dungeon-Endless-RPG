#include "helperUtils.h"

#include "./src/utils/debugUtils.h"

#include <chrono>
#include <cstdlib>
#include <thread>

void wait(int sec) {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void clearScreen() {
#ifdef _WIN32
    // Use "cls" to clear the screen on Windows
    system("cls");
#else
    // Use "clear" to clear the screen on Unix-like systems
    system("clear");
#endif

}

