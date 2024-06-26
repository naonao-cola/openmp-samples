cmake_minimum_required(VERSION 3.0.0)
project(quicksort-2 VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(quicksort-2 main.cpp)
target_link_libraries(quicksort-2 OpenMP::OpenMP_CXX)
