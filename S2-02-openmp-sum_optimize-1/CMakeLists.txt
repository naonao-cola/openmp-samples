cmake_minimum_required(VERSION 3.0.0)
project(sum_optimize-1 VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(sum_optimize-1 main.cpp)

target_link_libraries(sum_optimize-1 OpenMP::OpenMP_CXX)