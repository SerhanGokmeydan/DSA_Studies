cmake_minimum_required(VERSION 3.18)
project(DataStructures)

set(DIRECTORIES "Array" "Linked_List")

foreach(DIRECTORY IN LISTS DIRECTORIES)
    file(GLOB_RECURSE FILES CONFIGURE_DEPENDS "${DIRECTORY}/*.cpp")

    foreach(FILE IN LISTS FILES)
        get_filename_component(NAME ${FILE} NAME_WE) 

        set(TARGET_NAME "${DIRECTORY}_${NAME}")
        
        add_executable(${TARGET_NAME} ${FILE})

        set_target_properties(${TARGET_NAME} PROPERTIES 
            OUTPUT_NAME "${NAME}"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${DIRECTORY}")
    endforeach()
    

endforeach()