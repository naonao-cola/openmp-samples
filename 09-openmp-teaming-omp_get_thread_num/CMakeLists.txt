cmake_minimum_required(VERSION 3.0.0)
project(09-omp_get_thread_num VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(09-omp_get_thread_num main.cpp)

target_link_libraries(09-omp_get_thread_num OpenMP::OpenMP_CXX)

