cmake_minimum_required(VERSION 3.26)

project(coroamalib)

include_directories(include/ src/)

file(GLOB_RECURSE HEADERS include/*.h)
file(GLOB_RECURSE SOURCES src/*.c)

add_executable(coroamalib main.c ${HEADERS} ${SOURCES})