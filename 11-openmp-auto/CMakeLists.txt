cmake_minimum_required(VERSION 3.0.0)
project(11-openmp-auto VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(11-openmp-auto main.cpp)

target_link_libraries(11-openmp-auto OpenMP::OpenMP_CXX)
