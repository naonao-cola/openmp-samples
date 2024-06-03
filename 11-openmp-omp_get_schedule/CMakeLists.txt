cmake_minimum_required(VERSION 3.0.0)
project(11-openmp-omp_get_schedule VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(11-openmp-omp_get_schedule main.cpp)

target_link_libraries(11-openmp-omp_get_schedule OpenMP::OpenMP_CXX)
