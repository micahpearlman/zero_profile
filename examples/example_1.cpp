#include "zero_profile.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char **argv) {
    std::cout << "Example 1: Start" << std::endl;
    zero_profile::detail::invoke + []() {
        std::cout << "\tstart invoke>>>" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1313));
        std::cout << "\t<<<end invoke" << std::endl;
    };
    
    std::cout << "Example 1: End" << std::endl;
    return 1;
}