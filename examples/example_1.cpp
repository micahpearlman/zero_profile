#include "zero_profile.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char **argv) {
    std::cout << "Example 1: Start" << std::endl;

    // have zero profile execute the code 10 times while managing the begine and end
    zero_profile::profile p("example1_1", 10);
    p([&]() { std::this_thread::sleep_for(std::chrono::milliseconds(13)); });
    p.report();

    // manually set the begin and end
    zero_profile::profile p2("example1_2", 1);
    p2.begin();
    std::this_thread::sleep_for(std::chrono::milliseconds(13));
    p2.end();
    p2.report();

    std::cout << "Example 1: End" << std::endl;

    return 1;
}