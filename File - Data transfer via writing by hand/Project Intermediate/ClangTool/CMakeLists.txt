cmake_minimum_required(VERSION 3.15)
project(FindNamedClassTool)

set(CMAKE_CXX_STANDARD 17)

# Set the path to LLVM
set(LLVM_DIR /ubuntu/lib/share/llvm/cmake)

# Find LLVM
find_package(Clang REQUIRED CONFIG)

# Add LLVM include directories
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CLANG_INCLUDE_DIRS})

# Add LLVM definitions
add_definitions(${LLVM_DEFINITIONS})
add_definitions(${CLANG_DEFINITIONS})

# Add the executable
add_executable(FindNamedClassTool main.cpp)

# Link against LLVM libraries
target_link_libraries(FindNamedClassTool
  PRIVATE
  clang-cpp
  LLVM
)



