cmake_minimum_required(VERSION 3.19)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c get_next_line.h cmake-build-debug/get_next_line.c cmake-build-debug/get_next_line_utils.c)