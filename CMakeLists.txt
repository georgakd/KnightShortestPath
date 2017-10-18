cmake_minimum_required(VERSION 2.8.4)
project(ChessboardSimulation)
add_subdirectory(catch)
add_subdirectory(tests)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -ggdb")
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

set(SOURCE_FILES main.cpp Chess.h Knight.cpp Knight.h)


add_executable(ChessboardSimulation ${SOURCE_FILES})
