cmake_minimum_required(VERSION 3.0.0)
project(mergesort VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

include_directories(TimeCompute)
add_subdirectory(TimeCompute)

add_executable(mergesort main.cpp)
target_link_libraries(mergesort OpenMP::OpenMP_CXX TimeCompute)
