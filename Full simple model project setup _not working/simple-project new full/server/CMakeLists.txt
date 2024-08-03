add_executable(server server.cpp)

# Ensure the adapter files are generated before building the server
add_dependencies(server generate_adapters)

# Include directories
target_include_directories(server PRIVATE ../include ../build)
target_sources(server PRIVATE ../build/adapter.c)





