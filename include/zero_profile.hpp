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
    profile(const std::string &label, int32_t iterations = 1)
        : _iterations(iterations), _label(label) {}

    template <class Callable> void operator()(Callable c) {

        for (int i = 0; i < _iterations; i++) {
            begin();
            c();
            end();
        }
    }

    void begin() { _begin = std::chrono::steady_clock::now(); }

    void end() {
        std::chrono::steady_clock::time_point e =
            std::chrono::steady_clock::now();
        uint64_t diff_time =
            std::chrono::duration_cast<std::chrono::microseconds>(e - _begin)
                .count();

        _total_duration_micro_sec += diff_time;
        if (diff_time < _min_time) {
            _min_iter = _call_count;
            _min_time = diff_time;
        }
        if (diff_time > _max_time) {
            _max_iter = _call_count;
            _max_time = diff_time;
        }

        _call_count++;
    }

    void report() {
        double avg_time_millisec =
            (_total_duration_micro_sec * 0.001) / double(_call_count);
        double max_time_millisec = _max_time * 0.001;
        double min_time_millisec = _min_time * 0.001;
        std::cout << ":: " << _label << " ::" << std::endl;
        std::cout << "\tcall count: " << _call_count << std::endl;
        std::cout << "\taverage time milliseconds: " << std::fixed
                  << std::setprecision(5) << avg_time_millisec << std::endl;
        std::cout << "\tmin time milliseconds: " << std::fixed
                  << std::setprecision(5) << min_time_millisec << " at iteration: " << _min_iter <<std::endl;
        std::cout << "\tmax time milliseconds: " << std::fixed
                  << std::setprecision(5) << max_time_millisec << " at iteration: " << _max_iter << std::endl;

        std::cout << "--------------------------" << std::endl;
    }

  private:
    std::chrono::steady_clock::time_point _begin;
    uint64_t                              _call_count = 0;
    int32_t                               _iterations = 1;
    uint64_t                              _total_duration_micro_sec = 0;
    std::string                           _label;
    uint64_t                              _min_time = UINT64_MAX;
    uint64_t                              _max_time = 0;
    uint64_t                              _min_iter = -1;
    uint64_t                              _max_iter = -1;
};

} // namespace zero_profile

#endif