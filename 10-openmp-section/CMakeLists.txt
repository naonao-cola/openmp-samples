cmake_minimum_required(VERSION 3.0.0)
project(10-openmp-section VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(10-openmp-section main.cpp)

target_link_libraries(10-openmp-section OpenMP::OpenMP_CXX)