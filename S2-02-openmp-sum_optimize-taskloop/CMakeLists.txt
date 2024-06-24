cmake_minimum_required(VERSION 3.0.0)
project(sum_optimize-taskloop VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

include_directories(TimeCompute)
add_subdirectory(TimeCompute)

add_executable(sum_optimize-taskloop main.cpp)
target_link_libraries(sum_optimize-taskloop OpenMP::OpenMP_CXX TimeCompute)
