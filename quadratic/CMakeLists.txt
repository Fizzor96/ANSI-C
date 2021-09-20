cmake_minimum_required(VERSION 3.13)
project(quadratic)

set(CMAKE_C_STANDARD 99)

add_executable(quadraticapp main.c quadratic.h quadratic.c)

target_link_libraries(quadraticapp libm.so)