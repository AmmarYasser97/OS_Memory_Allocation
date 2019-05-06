cmake_minimum_required(VERSION 3.13)
project(OS_Memory_Allocation)

set(CMAKE_CXX_STANDARD 11)

add_executable(OS_Memory_Allocation main.cpp memory.cpp memory.h Block.cpp Block.h)