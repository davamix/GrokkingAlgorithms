cmake_minimum_required(VERSION 3.5)

find_package(Threads REQUIRED)

project("Algorithms Tests")

set(CMAKE_CXX_STANDARD 11)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)

if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)

if(result)
    message(FATAL_ERROR "Build step for googletest failed: ")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src 
                ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                EXCLUDE_FROM_ALL)

add_executable(project-test Algorithms-test.cpp)

target_link_libraries(project-test libproject gtest_main)

add_test(NAME Algorithms COMMAND project-test)
