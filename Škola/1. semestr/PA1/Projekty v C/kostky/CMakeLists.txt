cmake_minimum_required(VERSION 3.22)
project(kostky C)

set(CMAKE_C_STANDARD 99)

add_executable(kostky second_try.c)

target_link_libraries(kostky m)
