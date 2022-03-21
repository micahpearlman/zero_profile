#include "zero_profile.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char **argv) {
    std::cout << "Example 1: Start" << std::endl;

    zero_profile::profile p(10);
    for (int i = 0; i < 100; i++) {
        p([&]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(13));
        });
    }

    std::cout << "Example 1: End" << std::endl;

    return 1;
}