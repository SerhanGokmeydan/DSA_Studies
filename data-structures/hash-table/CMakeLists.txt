include_directories(include)

add_executable(Hash_Table main.cpp)

set_target_properties(Hash_Table PROPERTIES
    OUTPUT_NAME "main"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Hash_Table"
)