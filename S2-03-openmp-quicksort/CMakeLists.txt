cmake_minimum_required(VERSION 3.0.0)
project(quicksort VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(quicksort main.cpp)
target_link_libraries(quicksort OpenMP::OpenMP_CXX)
