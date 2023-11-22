# 3.20 for CMAKE_CXX_STANDARD == 23
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(ExpectedGCOV LANGUAGES CXX)

if(NOT ${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    message(FATAL_ERROR "Only gcc supported")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
if(BUILD_TESTING)
    set(CMAKE_CXX_FLAGS_DEBUG "-fprofile-arcs -ftest-coverage")
    find_package(GTest REQUIRED)

    add_executable(main main.cpp)
    target_link_libraries(main PRIVATE GTest::GTest)

    gtest_discover_tests(main)
endif()
