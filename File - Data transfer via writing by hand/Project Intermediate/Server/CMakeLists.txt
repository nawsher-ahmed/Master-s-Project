
cmake_minimum_required(VERSION 3.15)
project(Server)

set(CMAKE_C_STANDARD 11)

# Set the source files
set(SOURCE_FILES server.c)

# Add the executable
add_executable(Server ${SOURCE_FILES})

# Link against required libraries
target_link_libraries(Server
  PRIVATE
)


