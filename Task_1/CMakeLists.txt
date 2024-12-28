cmake_minimum_required(VERSION 3.10)
project(MyProject)


set(CMAKE_CXX_STANDARD 11)


file(GLOB SOURCES "function/*.cpp" "main.cpp")


add_executable(Task_1 ${SOURCES})


include_directories(${CMAKE_CURRENT_SOURCE_DIR})