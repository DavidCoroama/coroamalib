cmake_minimum_required(VERSION 3.26)

project(CoroamaLib)

include_directories(include/ src/)

file(GLOB_RECURSE HEADERS include/*.h)
file(GLOB_RECURSE SOURCES src/*.c)

add_library(coroama STATIC ${HEADERS} ${SOURCES})
target_include_directories(coroama PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(coroama PRIVATE -Wall -Wextra)

install(TARGETS coroama ARCHIVE DESTINATION lib PUBLIC_HEADER DESTINATION include/coroama)