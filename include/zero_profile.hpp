/**
 * @file zero_profile.hpp
 * @author Micah Pearlman
 * @brief
 * @version 0.1
 * @date 2022-03-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __ZERO_PROFILE_HPP__
#define __ZERO_PROFILE_HPP__
#include <iostream>
#include <functional>
#include <chrono>
#include <iomanip>

namespace zero_profile {

class profile {
  public:
    profile(int report_frequency = 1) : _report_frequency(report_frequency) {}
    template <class Callable> void operator()(Callable c) {
        std::chrono::steady_clock::time_point begin =
            std::chrono::steady_clock::now();
        c();
        std::chrono::steady_clock::time_point end =
            std::chrono::steady_clock::now();
        _total_duration_micro_sec += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        _call_count++;
        if (_call_count % _report_frequency == 0) {
            report();
        }
    }
    virtual ~profile() { report(); }

    void report() {
        double avg_time_millisec = (_total_duration_micro_sec * 0.001) / double(_call_count);
        std::cout << "call count: " << _call_count << std::endl;
        std::cout << "average time milliseconds: " << std::fixed << std::setprecision(2) << avg_time_millisec << std::endl;
    }

  private:
    int      _report_frequency = 1;
    uint64_t _call_count = 0;
    uint64_t _total_duration_micro_sec = 0;
};

} // namespace zero_profile

#endif