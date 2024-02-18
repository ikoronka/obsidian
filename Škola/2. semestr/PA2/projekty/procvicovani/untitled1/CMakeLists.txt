cmake_minimum_required(VERSION 3.22)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        REQUIRED)

add_executable(untitled1 main.cpp)
target_link_libraries(untitled1
        Qt5::Core
        )

