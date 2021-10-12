cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_STANDARD 99)
project(ApplicationExtra)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wunused-but-set-variable")

file(GLOB Application_SRC
     "src/*.h",
     "src/*.c"
)

add_executable(${CMAKE_PROJECT_NAME} ${Application_SRC})

target_link_libraries(${CMAKE_PROJECT_NAME} libm.so)