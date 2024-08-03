add_executable(client client.cpp)

# Ensure the adapter files are generated before building the client
add_dependencies(client generate_adapters)

# Include directories
target_include_directories(client PRIVATE ../include ../build)
target_sources(client PRIVATE ../build/adapter.c)





