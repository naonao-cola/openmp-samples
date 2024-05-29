cmake_minimum_required(VERSION 3.0.0)
project(09-omp_get_num_threads VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(09-omp_get_num_threads main.cpp)

target_link_libraries(09-omp_get_num_threads OpenMP::OpenMP_CXX)