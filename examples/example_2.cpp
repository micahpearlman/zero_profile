#include "zero_profile.hpp"
#include <iostream>
#include <random>

int main(int argc, char **argv) {
    std::cout << "Example 2: Start" << std::endl;
    std::random_device                                rd;
    std::mt19937_64                                   eng(13);//eng(rd());
    std::uniform_int_distribution<unsigned long long> distr;

    zero_profile::profile p("example1_2", 1);
    p.begin();

    for (int p = 0; p < 10000000; p++) {
        uint64_t i, n;
        bool     is_prime = true;

        n = distr(eng);
        // 0 and 1 are not prime numbers
        if (n == 0 || n == 1) {
            is_prime = false;
        }

        // loop to check if n is prime
        for (i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }

    }

    p.end();

    std::cout << "Example 2: End" << std::endl;

    return 1;
}