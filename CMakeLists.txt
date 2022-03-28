cmake_minimum_required(VERSION 3.0.0)
project(zero_profile VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(example_1 examples/example_1.cpp)
target_include_directories(example_1 PUBLIC include)
target_compile_features(example_1 PRIVATE cxx_std_17)

add_executable(example_2 examples/example_2.cpp)
target_include_directories(example_2 PUBLIC include)
target_compile_features(example_2 PRIVATE cxx_std_17)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
