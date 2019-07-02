cmake_minimum_required(VERSION 3.5.1)

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
    message(STATUS "GTest found (library: ${GTEST_LIBRARIES} include: ${GTEST_INCLUDE_DIRS})")
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
    add_test(${target} ${target})
endfunction(build_test)

if (BUILD_TESTS)
    # Common
    build_test(${CMAKE_CURRENT_SOURCE_DIR}/Test.cpp)
endif(BUILD_TESTS)