cmake_minimum_required(VERSION 3.0.0)
project(09-num_threads VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenMP REQUIRED)

add_executable(09-num_threads main.cpp)

target_link_libraries(09-num_threads OpenMP::OpenMP_CXX)


include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
