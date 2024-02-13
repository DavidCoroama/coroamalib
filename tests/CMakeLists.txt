cmake_minimum_required(VERSION 3.26)

project(coroamalib)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(${CMAKE_CURRENT_SOURCE_DIR}/lib/AllTests.cmake)

set(GTEST_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/gtest_main.cpp)

add_executable(runUnitTests ${CMAKE_CURRENT_SOURCE_DIR}/gtest_main.cpp ${COROAMALIB_UNIT_TESTS_SOURCE_FILES})

# set_target_properties(runUnitTests)
target_link_directories(runUnitTests PUBLIC ${CMAKE_SOURCE_DIR}/../cmake-build-debug/)
target_link_libraries(runUnitTests coroama GTest::gtest_main pthread)

include(GoogleTest)
gtest_discover_tests(runUnitTests)