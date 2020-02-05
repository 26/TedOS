cmake_minimum_required(VERSION 3.15)
project(toykernel C)

set(CMAKE_C_STANDARD 99)

add_executable(toykernel kernel.c)