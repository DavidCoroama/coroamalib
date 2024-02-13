cmake_minimum_required(VERSION 3.26)

project(coroamalib)

include(${CMAKE_CURRENT_SOURCE_DIR}/lib/AllTests.cmake)

set(GTEST_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/gtest_main.cpp)

add_executable(runUnitTests ${CMAKE_CURRENT_SOURCE_DIR}/gtest_main.cpp ${COROAMALIB_UNIT_TESTS_SOURCE_FILES})

# set_target_properties(runUnitTests)
target_link_directories(runUnitTests PUBLIC ${CMAKE_SOURCE_DIR}/../cmake-build-debug/)
target_link_libraries(runUnitTests coroama gtest gtest_main pthread)