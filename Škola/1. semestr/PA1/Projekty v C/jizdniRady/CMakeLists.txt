cmake_minimum_required(VERSION 3.22)
project(jizdniRady C)

set(CMAKE_C_STANDARD 99)

add_executable(jizdniRady main.c)
target_link_libraries(jizdniRady m)
