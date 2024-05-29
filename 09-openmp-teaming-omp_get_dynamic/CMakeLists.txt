cmake_minimum_required(VERSION 3.0.0)
project(09-opm_get_dynamic VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(09-opm_get_dynamic main.cpp)

target_link_libraries(09-opm_get_dynamic OpenMP::OpenMP_CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
