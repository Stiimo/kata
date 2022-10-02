cmake_minimum_required(VERSION 3.5)

project(kata LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS KEEP_RPATHS)

find_package(GTest REQUIRED)

enable_testing()
add_subdirectory(src)
add_subdirectory(tests/auto)
