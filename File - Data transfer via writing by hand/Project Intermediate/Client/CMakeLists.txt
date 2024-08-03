cmake_minimum_required(VERSION 3.15)
project(Client)

set(CMAKE_C_STANDARD 11)

# Set the source files
set(SOURCE_FILES client.c)

# Add the executable
add_executable(Client ${SOURCE_FILES})

# Link against required libraries
target_link_libraries(Client
  PRIVATE
)


