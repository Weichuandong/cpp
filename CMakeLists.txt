cmake_minimum_required(VERSION 3.25)
project(test VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
#add_compile_definitions("-fno-elide-constructors")


add_subdirectory(./Code)
add_executable(test test.cpp)