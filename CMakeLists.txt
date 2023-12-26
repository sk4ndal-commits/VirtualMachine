cmake_minimum_required(VERSION 3.27)
project(VirtualMachine)

set(CMAKE_CXX_STANDARD 17)

add_executable(VirtualMachine main.cpp
        token/Token.cpp)
