cmake_minimum_required(VERSION 3.22)
project(Task_2)


set(CMAKE_CXX_STANDARD 17)


file(GLOB SOURCES "function/*.cpp" "main.cpp")


add_executable(Task_2 ${SOURCES})


include_directories(${CMAKE_CURRENT_SOURCE_DIR})