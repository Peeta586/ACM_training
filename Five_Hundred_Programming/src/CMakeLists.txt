cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# # cmakelists 设置c++11
# include(CheckCXXCompilerFlag)
# CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
# CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
# if(COMPILER_SUPPORTS_CXX11)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# elseif(COMPILER_SUPPORTS_CXX0X)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# else()
#     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")

# endif()
## cmakelists 设置c++11

#include(CheckCXXCompilerFlag)
#CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
#CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0x)

#add_library(ACM
#        INTERFACE)
#
#target_sources(
#        ACM
#        INTERFACE
#        ${CMAKE_CURRENT_SOURCE_DIR}/Test.cpp
#)
#
#target_include_directories(
#        ACM
#        INTERFACE
#        "${CMAKE_SOURCE_DIR}/Header"
#)

# Find GTest
find_package(GTest)
if (GTest_FOUND)
    message(STATUS "GTest found (library: ${GTest_LIBRARIES} include: ${GTest_INCLUDE_DIRS})")
else()
    message(STATUS "GTest not found")
    if (BUILD_TESTS)
        message(FATAL_ERROR "GTest required to build tests")
    endif ()
endif()

# TODO: figure out a nice way to add linking and definitions
# add linking in a
function(build_test SRCFILE)
    get_filename_component(src_name ${SRCFILE} NAME_WE)
    set(target "${src_name}")
    add_executable(${target} ${SRCFILE})
    target_link_libraries(
            ${target}
            PRIVATE
            GTest::GTest
            GTest::Main
    )
    target_include_directories(
            ${target}
            PRIVATE
            ${CMAKE_SOURCE_DIR}/Header
    )
    
    # 参数什么意思
    add_test(${target} ${target})
endfunction(build_test)

if (BUILD_TESTS)
    # Common
    build_test(${CMAKE_CURRENT_SOURCE_DIR}/Test.cpp)
endif(BUILD_TESTS)