cmake_minimum_required(VERSION 3.15)
project(CombinedProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Add subdirectories for each part of the project
add_subdirectory(ClangTool)
add_subdirectory(Server)
add_subdirectory(Client)


