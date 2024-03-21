cmake_minimum_required(VERSION 3.0.0)
project(02-05 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(OpenMP REQUIRED)

add_executable(02-05 main.cpp)

target_link_libraries(02-05 OpenMP::OpenMP_CXX)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
