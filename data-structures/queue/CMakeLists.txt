include_directories(include)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(Queue_App ${SOURCES})

set_target_properties(Queue_App PROPERTIES
    OUTPUT_NAME "main"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Queue"
)