cmake_minimum_required(VERSION 3.0.0)
project(S2-01 VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(S2-01 main.cpp)

target_link_libraries(S2-01 OpenMP::OpenMP_CXX)