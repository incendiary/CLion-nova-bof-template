cmake_minimum_required(VERSION 3.15)
project(CLionBOFTemplate)

# Set the C standard
set(CMAKE_C_STANDARD 11)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add example BOFs as libraries (optional)
add_library(example_bof SHARED examples/hello/hello.c)

# Add a library for user BOFs
file(GLOB USER_BOFS src/*.c)
add_library(user_bofs SHARED ${USER_BOFS})

# Add tests as an executable
file(GLOB TEST_SOURCES tests/src/*.c)
add_executable(bof_tests ${TEST_SOURCES})

# Compiler flags for BOFs
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DBOF")

