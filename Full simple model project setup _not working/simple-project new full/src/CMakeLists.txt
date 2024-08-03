



add_executable(FindNamedStructTool main.cpp)
add_executable(AdapterGenerator adapter_generator.cpp)

add_custom_target(generate_adapters
    COMMAND FindNamedStructTool ../include/Model2.h
    COMMAND AdapterGenerator
    DEPENDS FindNamedStructTool AdapterGenerator
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    BYPRODUCTS ${CMAKE_BINARY_DIR}/extracted_data.txt ${CMAKE_BINARY_DIR}/adapter.h ${CMAKE_BINARY_DIR}/adapter.c
)


