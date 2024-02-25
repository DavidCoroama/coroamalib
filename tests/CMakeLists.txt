cmake_minimum_required(VERSION 3.5)
project(coroama_unit_test)

include(${CMAKE_CURRENT_SOURCE_DIR}/lib/AllTests.cmake)

set(GTEST_MAIN gtest_main.cpp)

add_executable(runUnitTests ${GTEST_MAIN} ${COROAMA_UNIT_TESTS_SOURCE_FILES})

target_link_libraries(runUnitTests lib gtest gtest_main pthread)