cmake_minimum_required(VERSION 3.31)
project(Hackatime_Info)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(Hackatime_Info main.cpp)
