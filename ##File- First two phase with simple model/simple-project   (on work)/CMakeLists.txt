cmake_minimum_required(VERSION 3.10)
project(SimpleProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(FindNamedStructTool src/main.cpp)
add_executable(AdapterGenerator src/adapter_generator.cpp)

