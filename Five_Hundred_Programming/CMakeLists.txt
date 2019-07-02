cmake_minimum_required(VERSION 3.5.1)

project(five_hundred_programming)


set(CMAKE_CXX_STANDARD 11)
option(BUILD_TESTS "Build tests for ACM" ON)
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(${CMAKE_SOURCE_DIR}/src)
endif()

# add_subdirectory(src)
# include_directories(Header)

# add_executable(five_hundred_programming main.cpp)

