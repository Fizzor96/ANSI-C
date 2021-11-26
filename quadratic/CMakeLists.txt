cmake_minimum_required(VERSION 3.13)
project(quadratic)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")

add_executable(quadraticapp main.c quadratic.h quadratic.c)

IF (WIN32)
ELSE()
     target_link_libraries(${CMAKE_PROJECT_NAME} libm.so)
ENDIF()