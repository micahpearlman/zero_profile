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
namespace zero_profile {
namespace detail {

enum class invoke_t {};

template<class Callable>
auto operator+(invoke_t, Callable c) -> decltype(c()) {
    std::cout << "...invoke..." << std::endl;
    c();
    std::cout << "...invoke..." << std::endl;
}

constexpr zero_profile::detail::invoke_t invoke{};

}
}

#endif