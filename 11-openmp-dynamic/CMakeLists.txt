cmake_minimum_required(VERSION 3.0.0)
project(11-openmp-dynamic VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(11-openmp-dynamic main.cpp)

target_link_libraries(11-openmp-dynamic OpenMP::OpenMP_CXX)